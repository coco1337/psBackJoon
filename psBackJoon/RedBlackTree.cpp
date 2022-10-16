#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

enum class COLOR{
  BLACK,
  RED,
};

struct Node {
  int data;
  shared_ptr<Node> left = nullptr;
  shared_ptr<Node> right = nullptr;
  shared_ptr<Node> parent = nullptr;
  COLOR color = COLOR::BLACK;
};

typedef shared_ptr<Node> NodePtr;

class RBTree {
public:
  RBTree() {
    leafNode = make_shared<Node>();
    leafNode->color = COLOR::BLACK;
    leafNode->right = nullptr;
    leafNode->left = nullptr;
    leafNode->parent = nullptr;
    root = leafNode;
  }

  void Insert(int item) {
    auto target = root;
    NodePtr targetParent = nullptr;
    // make new node
    auto newNode = make_shared<Node>();
    newNode->data = item;
    newNode->color = COLOR::RED;
    newNode->parent = nullptr;
    newNode->left = leafNode;
    newNode->right = leafNode;

    // insert BST
    // 어디 추가할지 찾기
    while (target != leafNode) {
      targetParent = target;
      if (target->data < item) target = target->right;
      else target = target->left;
    }

    // 부모 설정
    newNode->parent = targetParent;

    if (targetParent == nullptr)  // 부모노드가 없다면 root
      root = newNode;
    else if (newNode->data > targetParent->data)
      targetParent->right = newNode;
    else
      targetParent->left = newNode;

    if (newNode->parent == nullptr) {
      // 새로 생성한 노드가 root aus
      newNode->color = COLOR::BLACK;
      return;
    }

    if (newNode->parent->parent == nullptr) // newNode의 부모노드가 root면 RED 그대로
      return;

    // RB tree에 맞게 색 수정
    InsertFix(newNode);
  }

  bool Delete(int item) {
    auto target = FindDuplicateData(item);
    if (!target) return false; // 중복시 일단 false

    NodePtr x = nullptr, y = nullptr;
    auto cacheColor = target->color;

    // 자식 없거나 1개인경우 삭제할 노드가 BLACK이면 double red 확인
    if (target->left == leafNode) {
      x = target->right;
      Replace(target, target->right);
    } else if (target->right == leafNode) {
      x = target->left;
      Replace(target, target->left);
    } else {
      // target 보다 큰 수 중 가장 작은 수
      y = FindMin(target->right);
      cacheColor = y->color;
      x = y->right;

      if (y->parent == target)
        x->parent = y;
      else {
        Replace(y, y->right);
        y->right = target->right;
        y->right->parent = y;
      }

      Replace(target, y);
      y->left = target->left;
      y->left->parent = y;
      y->color = target->color;
    }

    target = nullptr;
    if (cacheColor == COLOR::BLACK) DeleteFix(x);

    return true;
  }

  /// 동일한 데이터가 트리 내부에 있는지 확인
  NodePtr FindDuplicateData(int item) {
    auto t = root;
    NodePtr parent = nullptr;

    while (t != nullptr && t->data != item) {
      parent = t;
      t = (item < parent->data) ? parent->left : parent->right;
    }

    return t;
  }

  void Print(NodePtr n){
    if (n == leafNode) return;
    Print(n->left);
    cout << n->data << "(" << (n->color == COLOR::BLACK ? "BLACK" : "RED") << ") ";
    Print(n->right);
  }

private:
  /// n 기준 좌회전
  void RotateLeft(NodePtr n)
  {
    NodePtr t;

    t = n->right;
    n->right = t->left;
    if (t->left != leafNode)
      t->left->parent = n;

    t->parent = n->parent;

    if (!n->parent)
      root = t;
    else if (n == n->parent->left)
      n->parent->left = t;
    else
      n->parent->right = t;

    n->parent = t;
    t->left = n;
  }

  /// n 기준 우회전
  void RotateRight(NodePtr n)
  {
    NodePtr t;

    t = n->left;
    n->left = t->right;
    if (t->right != leafNode)
      t->right->parent = n;

    t->parent = n->parent;

    if (!n->parent)
      root = t;
    else if (n == n->parent->left)
      n->parent->left = t;
    else
      n->parent->right = t;

    n->parent = t;
    t->right = n;
  }

  NodePtr FindMin(NodePtr n) {
    while (n->left != leafNode) n = n->left;
    return n;
  }

  NodePtr FindMax(NodePtr n) {
    while (n->right != leafNode) n = n->right;
    return n;
  }

  /// a를 b로 교체
  void Replace(NodePtr a, NodePtr b) {
    if (a->parent == nullptr) root = b;
    else if (a == a->parent->left) a->parent->left = b;
    else a->parent->right = b;

    b->parent = a->parent;
  }

  /// Binary Search Tree 삽입 이후 색 고치기
  void InsertFix(NodePtr n) {
    // root 가 아니고 부모 노드가 RED
    while (n != root && n->parent->color == COLOR::RED) {
      auto grandParent = n->parent->parent;
      auto uncle = (n->parent == grandParent->left) ? grandParent->right : grandParent -> left;
      bool isLeft = n->parent == grandParent->left;

      // 삼촌노드가 RED
      if (uncle && uncle->color == COLOR::RED) {
        n->parent->color = COLOR::BLACK;
        uncle->color = COLOR::BLACK;
        grandParent->color = COLOR::RED;
        n = grandParent;
      } else {
        if (n == (isLeft ? n->parent->right : n->parent->left)) {
          n = n->parent;
          isLeft ? RotateLeft(n) : RotateRight(n);
        }

        n->parent->color = COLOR::BLACK;
        grandParent->color = COLOR::RED;
        isLeft ? RotateRight(grandParent) : RotateLeft(grandParent);
      }
    }

    // root 컬러를 다시 BLACK 으로 바꿔주기
    root->color = COLOR::BLACK;
  }

  void DeleteFix(NodePtr n) {
    NodePtr sibling;

    // root가 되거나 double black 없어질 때까지 반복
    while (n != root && n->color == COLOR::BLACK) {
      if (n == n->parent->left) {
        // n 이 왼쪽 자식일경우
        sibling = n->parent->right;

        // 형제가 RED
        if (sibling->color == COLOR::RED) {
          sibling->color = COLOR::BLACK;
          n->parent->color = COLOR::RED;
          RotateLeft(n->parent);
          sibling = n->parent->right;
        }

        // 형제의 자식이 둘다 BLACK
        if (sibling->left->color == COLOR::BLACK && sibling->right->color == COLOR::BLACK) {
          sibling->color = COLOR::RED;
          n = n->parent;
        } else {
          // 형제의 오른쪽자식이 BLACK
          if (sibling->right->color == COLOR::BLACK) {
            sibling->left->color = COLOR::BLACK;
            sibling->color = COLOR::RED;
            RotateRight(sibling);
            sibling = n->parent->right;
          }

          //
          sibling->color = n->parent->color;
          n->parent->color = COLOR::BLACK;
          sibling->right->color = COLOR::BLACK;
          RotateLeft(n->parent);
          n = root;
        }
      } else {
        // n이 오른쪽 자식일경우, 왼쪽 자식일 경우의 반대
        sibling = n->parent->left;

        if (sibling->color == COLOR::RED) {
          sibling->color = COLOR::BLACK;
          n->parent->color = COLOR::RED;
          RotateRight(n->parent);
          sibling = n->parent->left;
        }

        if (sibling->left->color == COLOR::BLACK && sibling->right->color == COLOR::BLACK) {
          sibling->color = COLOR::RED;
          n = n->parent;
        } else {
          if (sibling->left->color == COLOR::BLACK){
            sibling->right->color = COLOR::BLACK;
            sibling->color = COLOR::RED;
            RotateLeft(sibling);
            sibling = n->parent->left;
          }

          sibling->color = n->parent->color;
          n->parent->color = COLOR::BLACK;
          sibling->left->color = COLOR::BLACK;
          RotateRight(n->parent);
          n = root;
        }
      }
    }

    n->color = COLOR::BLACK;
    root->color = COLOR::BLACK;
  }

public:
  NodePtr root;

private:
  NodePtr leafNode;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  RBTree tree;

  int menu = 0;
  int num = 0;
  while (true) {
    cout << "Menu\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Print\n";
    cout << "4. cls\n";
    cin >> menu;

    switch (menu){
      case 1:
      {
        cout << "type integer :\n";
        cin >> num;
        if (tree.FindDuplicateData(num)) {
          cout << "data duplicate\n";
          break;
        }

        tree.Insert(num);
        break;
      }

      case 2:
      {
        cout << "type integer :\n";
        cin >> num;
        if (!tree.Delete(num)) {
          cout << "data isn't exist\n";
          break;
        }

        break;
      }

      case 3:
      {
        tree.Print(tree.root);
        cout << '\n';
        break;
      }

      case 4:
      {
        system("cls");
        break;
      }
    }
  }
}