/*
    struct made by Alyona Pisareva
*/


#include <iostream>
using namespace std;
 
enum COLOR { RED=1, BLACK };

struct Node {
  int val;
  COLOR color;
  Node *left, *right, *parent;
  Node(int Data)
  {
    val=Data;
    parent = left = right = NULL; // Узел создается во время вставки и Узел красный при вставке
    color = RED;
  }
  Node *uncle(Node *x) { // возвращает указатель на дядю
    // Если нет родителя или дедушки, то нет дяди
    if (parent == NULL or parent->parent == NULL)
      return NULL;
    if (parent==parent->parent->left) // дядя справа
      return parent->parent->right;
    else // дядя слева
      return parent->parent->left;
  }
  // возвращает указатель на брата
  Node *sibling(Node *x) {
    // родной нуль, если нет родителя
    if (parent == NULL)
      return NULL;
    if (x==parent->left)
      return parent->right;
    return parent->left;
  }
  // перемещаем узел вниз и перемещаем данный узел на его место
  void moveDown(Node *nParent) {
    if (parent != NULL) {
      if (nParent == parent->left) {
        parent->left = nParent;
      } else {
        parent->right = nParent;
      }
    }
    nParent->parent = parent;
    parent = nParent;
  }
  bool hasRedChild() {
    return (left != NULL and left->color == RED) or
           (right != NULL and right->color == RED);
  }
};

struct RBTree {
  Node *root;
  void leftRotate(Node *x) {// влево поворачивает данный узел
    Node *nParent = x->right; // новый родитель будет правым потомком узла
    if (x == root)// обновляем корень, если текущий узел является корней
      root = nParent;
    x->moveDown(nParent);
    // соединяем x с левым элементом нового родителя
    x->right = nParent->left;
    // соединяем левый элемент нового родителя с узлом
    // если не ноль
    if (nParent->left != NULL)
      nParent->left->parent = x;
    // соединяем нового родителя с x
    nParent->left = x;
  }
  void rightRotate(Node *x) {
    Node *nParent = x->left;// новый родитель будет левым потомком узла
    if (x == root)
      root = nParent;
    x->moveDown(nParent);
    x->left = nParent->right;
    if (nParent->right != NULL)
      nParent->right->parent = x;
    nParent->right = x;
  }
  void swapColors(Node *x1, Node *x2) {
    COLOR temp;
    temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
  }
  void swapValues(Node *u, Node *v) {
    int temp;
    temp = u->val;
    u->val = v->val;
    v->val = temp;
  }
  void fixRedRed(Node *x) {// исправить красный красный на данном узле
    if (x == root) {// если x является корневым цветом, он черный и возвращает
      x->color = BLACK;
      return;
    }
    // инициализируем родителя, дедушку, дедушку
    Node *parent = x->parent, *grandparent = parent->parent,
         *uncle = x->uncle(x);
    if (parent->color != BLACK) {
      if (uncle != NULL && uncle->color == RED) {
        // дядя красный, выполнить перекрашивание и рекурсировать
        parent->color = BLACK;
        uncle->color = BLACK;
        grandparent->color = RED;
        fixRedRed(grandparent);
      } else {
        // Остальное выполнить LR, LL, RL, RR
        if (parent== parent->parent->left) {
          if (x==x->parent->left) {
            // для левого и правого
            swapColors(parent, grandparent);
          } else {
            leftRotate(parent);
            swapColors(x, grandparent);
          }
          // для левого левого и левого правого
          rightRotate(grandparent);
        } else {
          if (x==x->parent->left) {
            // для правого левого
            rightRotate(parent);
            swapColors(x, grandparent);
          } else {
            swapColors(parent, grandparent);
          }
          // для правого, правого и правого левого
          leftRotate(grandparent);
        }
      }
    }
  }
  // найти узел, у которого нет левого потомка
  // в поддереве данного узла
  Node *successor(Node *x) {
    Node *temp = x;
    while (temp->left != NULL)
      temp = temp->left;
    return temp;
  }
  // найти узел, который заменяет удаленный узел в BST
  Node *BSTreplace(Node *x) {
    if (x->left != NULL and x->right != NULL)// когда у узла 2 ребенка
      return successor(x->right);
    if (x->left == NULL and x->right == NULL)// когда лист
      return NULL;
    if (x->left != NULL)// когда одинокий ребенок
      return x->left;
    else
      return x->right;
  }
  // удаляет указанный узел
  void deleteNode(Node *v) {
    Node *u = BSTreplace(v);
    // True, когда u и v оба черные
    bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
    Node *parent = v->parent;
    if (u == NULL) { // U - NULL, поэтому v - лист
      if (v == root) {// v - root, делая root пустым
        root = NULL;
      } else {
        if (uvBlack) {// u и v оба черные
          // v - лист, исправить двойное черное на v
          fixDoubleBlack(v);
        } else {// U или V красный
          if (v->sibling(v) != NULL)// брат не нулевой, сделай его красным
            v->sibling(v)->color = RED;
        }
        // удаляем v из дерева
        if (v == v->parent->left) {
          parent->left = NULL;
        } else {
          parent->right = NULL;
        }
      }
      delete v;
      return;
    }
    if (v->left == NULL or v->right == NULL) {// у v есть 1 ребенок
      if (v == root) {// v - root, присваиваем значение u v и удаляем u
        v->val = u->val;
        v->left = v->right = NULL;
        delete u;
      } else {
        // Отсоединяем v от дерева и поднимаем
        if (v== v->parent->left) {
          parent->left = u;
        } else {
          parent->right = u;
        }
        delete v;
        u->parent = parent;
        if (uvBlack) {
          // вы и v оба черные, исправьте двойной черный у вас
          fixDoubleBlack(u);
        } else {
          // красный или красный, черный цвет
          u->color = BLACK;
        }
      }
      return;
    }
    // у v есть 2 потомка, поменяйте местами значения с преемником и recurse
    swapValues(u, v);
    deleteNode(u);
  }
  void fixDoubleBlack(Node *x) {
    if (x == root)
      // Достигнут корень
      return;
    Node *sibling = x->sibling(x), *parent = x->parent;
    if (sibling == NULL) {
      // Никакого родства, двойной черный оттолкнут
      fixDoubleBlack(parent);
    } else {
      if (sibling->color == RED) {
        // родной красный
        parent->color = RED;
        sibling->color = BLACK;
        if (sibling== sibling->parent->left) {
          // левый регистр
          rightRotate(parent);
        } else {
          // правый случай
          leftRotate(parent);
        }
        fixDoubleBlack(x);
      } else {
        // брат черный
        if (sibling->hasRedChild()) {
          // хотя бы 1 красный ребенок
          if (sibling->left != NULL and sibling->left->color == RED) {
            if (sibling== sibling->parent->left) {
              // слева налево
              sibling->left->color = sibling->color;
              sibling->color = parent->color;
              rightRotate(parent);
            } else {
              // правый левый
              sibling->left->color = parent->color;
              rightRotate(sibling);
              leftRotate(parent);
            }
          } else {
            if (sibling== sibling->parent->left) {
              // лево право
              sibling->right->color = parent->color;
              leftRotate(sibling);
              rightRotate(parent);
            } else {
              // право-право
              sibling->right->color = sibling->color;
              sibling->color = parent->color;
              leftRotate(parent);
            }
          }
          parent->color = BLACK;
        } else {
          // 2 черных ребенка
          sibling->color = RED;
          if (parent->color == BLACK)
            fixDoubleBlack(parent);
          else
            parent->color = BLACK;
        }
      }
    }
  }
  // рекурсивно печатает
  void inorder(Node *x) {
    if (x == NULL)
      return;
    inorder(x->left);
    cout << x->val << " " << x->color << endl;
    inorder(x->right);
  }
 
 
  // инициализируем root
  RBTree() { root = NULL; }
  Node *getRoot() { return root; }
  // ищет заданное значение
  // если найден, возвращает узел (используется для удаления)
  // else возвращает последний узел при обходе (используется при вставке)
  Node *search(int n) {
    Node *temp = root;
    while (temp != NULL) {
      if (n < temp->val) {
        if (temp->left == NULL)
          break;
        else
          temp = temp->left;
      } else if (n == temp->val) {
        break;
      } else {
        if (temp->right == NULL)
          break;
        else
          temp = temp->right;
      }
    }
    return temp;
  }
  // вставляет данное значение в дерево
  void insert(int n) {
    Node *newNode = new Node(n);
    if (root == NULL) {
      // когда root равен null
      // просто вставляем значение в корень
      newNode->color = BLACK;
      root = newNode;
    } else {
      Node *temp = search(n);
      if (temp->val == n) {
        // возвращаем, если значение уже существует
        return;
      }
      // если значение не найдено, поиск возвращает узел
      // где значение должно быть вставлено
      // подключаем новый узел к правильному узлу
      newNode->parent = temp;
      if (n < temp->val)
        temp->left = newNode;
      else
        temp->right = newNode;
      // исправить красный красный voilaton, если существует
      fixRedRed(newNode);
    }
  }
  // служебная функция, которая удаляет узел с заданным значением
  void deleteByVal(int n) {
    if (root == NULL)
      // Дерево пусто
      return;
    Node *v = search(n), *u;
    if (v->val != n) {
      cout << "No node found to delete with value:" << n << endl;
      return;
    }
    deleteNode(v);
  }
  // выводит порядок дерева
 
  void printInOrder() {
    cout << "Inorder: " << endl;
    if (root == NULL)
      cout << "Tree is empty" << endl;
    else
      inorder(root);
    cout << endl;
  }
};

// проверка
int PrintInMass1(Node* p, COLOR* mass, int index = 0)
{
  	if (p->left != NULL)
  	{
  		index = PrintInMass1(p->left, mass, index);
  	}
  	mass[index] = p->color;
  	index += 1;
  	if (p->right != NULL)
  	{
  		index = PrintInMass1(p->right, mass, index);
  	}
  	return index;
}
//use this
void PrintInMass(Node* p, COLOR* mass)
{
  	int a;
  	a = PrintInMass1(p, mass);
}

bool IfTheSame(Node* p, COLOR* mass, int n)
{
  	COLOR mass1[n];
  	PrintInMass(p, mass1);
  	for (int i = 0; i < n; i++)
  	{
  		if (mass1[i] != mass[i]){
  			return false;
  		}
  	}
  	return true;
}
