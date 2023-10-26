#include "tree.h"

void Tree::add(const string word, int count, TreeNode* node)
{
    if (node == nullptr) node = head;  // На начало рекурсии, мы ставим элемент на головной
    if (node == nullptr) {  // Если дерево пустое, то добавляем первый элемент
        head = node = new TreeNode{ word, count };
        return;
    }
    int res = node->word.compare(word);  // производим сравнение
    if (res < 0) {  // Если наше слово БОЛЬШЕ чем в узле, то идем вправо
        if (node->right != nullptr) add(word, count, node->right);  // Если справа есть ветвь, то рекурсивно повторяем действие для правой ветви
        else node->right = new TreeNode{ word, count };  // Иначе создаем новый лист справа
        return;
    }
    if (res > 0) { // Если наше слово МЕНЬШЕ чем в узле, то идем влево
        if (node->left != nullptr) add(word, count, node->left);  // Если слева есть ветвь, то рекурсивно повторяем действие для левой ветви
        else node->left = new TreeNode{ word, count };  // Иначе создаем новый лист слева
        return;
    }
    node->count += 1;  // Если слова совпадают, то увеличиваем кол-во слов на 1
    return;
}

void Tree::printCount(TreeNode* node) {
    if (node == nullptr) node = head;  // Если нет аргумента, то задаем головной элемент
    if (node == nullptr) return;
    if (node->left != nullptr) printCount(node->left);  // Если есть левый элемент, то рекурсивно влево (в сторону меньшего элемента)
    std::cout << node->word << ": " << node->count << std::endl;  // Выводим текущий элемент
    if (node->right != nullptr) printCount(node->right);  // Если есть правый элемент, то рекурсивно вправо (в сторону большего элемента)
}

void Tree::printTree(TreeNode* node, int level, int side) {
    if (node == nullptr) node = head;  // Если элемент не задан, то начинаем с головы
    if (node == nullptr) return;  // Если головы нет, то че рисовать то, лол
    if (node->right != nullptr) printTree(node->right, level + 1, 1);  //  У нас дерево повернуто на 90 градусов, так что первым делом отрисуем рекурсивно правые ветви
    for (int i = 0; i < level; ++i) std::cout << "     ";  // За счет накапливаемого уровня делаем n-ное количество отступов для красивого вида
    if (side > 0) std::cout << '/';  // За счет стороны, для удобства показываем, в какой стороне предок ветки
    else if (side < 0) std::cout << '\\';
    std::cout << node->word << " [lvl: " << level << "]" << std::endl;  // выводим сам элемент (для упрощения выводим его уровень)
    if (node->left != nullptr) printTree(node->left, level + 1, -1);  // После вывода самого элемента, мы можем уже вывести и левые ветви
}

int Tree::removeElement(const string word, TreeNode* node, int level) {
    if (head == nullptr) return 0;
    if (level == 0) node = head;
    if (node == nullptr) return 0;
    
    int res = node->word.compare(word);  // производим сравнение
    if (res < 0) return removeElement(word, node->right, level + 1);
    else if (res > 0) return removeElement(word, node->left, level + 1);
    else {
        int count = node->count;
        if (node->right == nullptr || node->left == nullptr) {
            TreeNode* rmnode = (node->right == nullptr ? node->left : node->right);
            *(node) = *(rmnode);
            delete rmnode;
        } else remove(node->left, node);
        return count;
    }
}

void Tree::remove(TreeNode* node, TreeNode* rmnode) {
    if (node->right != nullptr) remove(node->right, rmnode);
    else {
        rmnode->word = node->word;
        rmnode->count = node->count;
        if (node->left != nullptr) {
            TreeNode* rm2node = node->left;
            *node = *(node->left);
            delete rm2node;
        }
    }
}

void Tree::setCount(const string word, const int count) {
    return;
}

// Лаба в разработке
TreeNode::~TreeNode() {
    left = right = nullptr;
    delete left, right;
}
