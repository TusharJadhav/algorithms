#ifndef INCLUDE_ALGORITHMS_BINARY_SEARCH_TREE_H_
#define INCLUDE_ALGORITHMS_BINARY_SEARCH_TREE_H_
#include <stddef.h>
#include <functional>
#include <memory>
#include <vector>
#include <stdexcept>
/*
This class implemets tradition binary search tree
*/

namespace algorithms {
  template <typename _tp>
  class BinarySearchTree {
    public:
      typedef _tp value_type;
    private:
      typedef struct tagTreeNode{
        value_type val_;
        std::unique_ptr<tagTreeNode> left_child_;
        std::unique_ptr<tagTreeNode> right_child_;
        size_t size_;

        tagTreeNode(const value_type& val) :
          val_{val},
          size_{1}
        {}
      } TreeNode;

      std::function<bool(const value_type&, const value_type&)> comparer_;
      std::unique_ptr<TreeNode> root_;

    public:
      BinarySearchTree(std::function<bool(const value_type&, const value_type&)> comparer = std::less<value_type>()) :
        comparer_{comparer}
      {}

      void Insert(const value_type& value){
        root_ = Insert(std::move(root_), value); 
      }

      std::vector<value_type> GetElementsInOrder() {
        if(root_ == nullptr)
          return {};

        std::vector<value_type> list;
        GetElementsInOrder(root_.get(), list);

        return std::move(list);
      }

      bool Contains(const value_type& value){
        return Contains(root_.get(), value);
      }

      bool IsEmpty(){
        return root_ == nullptr;
      }

      size_t Size(){
        if(root_ == nullptr)
          return 0;

        return root_->size_;
      }

      value_type Min(){
        if(root_ == nullptr)
          throw std::underflow_error("Invalid operation called on an empty binary search tree");

        auto curr = root_.get();

        while(curr->left_child_ != nullptr){
          curr = curr->left_child_.get();
        }

        return curr->val_;
      }

      value_type Max(){
        if(root_ == nullptr)
          throw std::underflow_error("Invalid operation called on an empty binary search tree");

        auto curr = root_.get();

        while(curr->right_child_ != nullptr){
          curr = curr->right_child_.get();
        }

        return curr->val_;
      }

    private:
      std::unique_ptr<TreeNode> Insert(std::unique_ptr<TreeNode> node, const value_type& value) {
        if(node == nullptr)
          return std::make_unique<TreeNode>(value);

        if(comparer_(value, node->val_)) {
          node->left_child_ = Insert(std::move(node->left_child_), value);
        }
        else
        if(comparer_(node->val_, value)) {
          node->right_child_ = Insert(std::move(node->right_child_), value);
        }
        else {
          node->val_ = value;
        }

        node->size_ = (node->left_child_ ? node->left_child_->size_ : 0) + 1 +
                      (node->right_child_ ? node->right_child_->size_ : 0);

        return std::move(node);
      }

      void GetElementsInOrder(TreeNode* node, std::vector<value_type>& elements) {
        if(node == nullptr)
          return;
        
        GetElementsInOrder(node->left_child_.get(), elements);
        elements.push_back(node->val_);
        GetElementsInOrder(node->right_child_.get(), elements);
      }

      bool Contains(TreeNode* node, const value_type& value){
        if(node == nullptr)
          return false;

        auto less = comparer_(value, node->val_);
        auto greater = comparer_(node->val_, value);

        if(!less && !greater)
          return true;

        if(Contains(node->left_child_.get(), value))
          return true;

        return Contains(node->right_child_.get(), value);
      }
  };
}

#endif //INCLUDE_ALGORITHMS_BINARY_SEARCH_TREE_H_

