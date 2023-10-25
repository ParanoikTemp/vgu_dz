#include "tree.h"

TreeNode* Tree::findMin(string notWord, TreeNode* node)
{
    if (node == nullptr) node = head;  // Изначально идем с головы дерева
    if (node == nullptr) return nullptr;  // Если головы нет то пи***ц
    if (node->left != nullptr)
    return nullptr;
}

void Tree::add(const string word, TreeNode* node)
{
    if (node == nullptr) node = head;  // На начало рекурсии, мы ставим элемент на головной
    if (node == nullptr) {  // Если дерево пустое, то добавляем первый элемент
        head = node = new TreeNode{ word };
        return;
    }
    int res = node->word.compare(word);  // производим сравнение
    if (res < 0) {  // Если наше слово БОЛЬШЕ чем в узле, то идем вправо
        if (node->right != nullptr) add(word, node->right);  // Если справа есть ветвь, то рекурсивно повторяем действие для правой ветви
        else node->right = new TreeNode{ word };  // Иначе создаем новый лист справа
        return;
    }
    if (res > 0) { // Если наше слово МЕНЬШЕ чем в узле, то идем влево
        if (node->left != nullptr) add(word, node->left);  // Если слева есть ветвь, то рекурсивно повторяем действие для левой ветви
        else node->left = new TreeNode{ word };  // Иначе создаем новый лист слева
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

int Tree::removeElement(const string word, TreeNode* node) {
    if (node == nullptr) node = head;  // Если пусто, то голова
    if (node == nullptr) return 0;  // Если головы нет, то ниче нет
    int count;
    if (node->word == word) {  // Если совпадает, то это головной элемент. Если удаляем головной элемент, то очищаем значение, а головную ссылку ведем в пустоту
        count = node->count;
        delete node;
        head = nullptr;
    }
    else {
        TreeNode* rmnode = nullptr; // Удаляемая нода
        int res = node->word.compare(word);  // производим сравнение
        if (res < 0) {  // Если наше слово БОЛЬШЕ чем в узле, то идем вправо
            if (node->right == nullptr) return 0;  // Если справа числа нет, то капут. Нет такого элемента!
            if (node->right->word == word) rmnode = node->right;  // Если следующий элемент совпадает, то делаем на него ссылку
            else return removeElement(word, node->right);  // Иначе рекурсивно идем вправо
            if (rmnode->left == nullptr) {  // Если нет левой ветви, то просто заменяем элемент на тот, что справа.
                count = rmnode->count;
                node->right = rmnode->right;
                delete rmnode;
                return count;
            }
            else if (rmnode->right == nullptr) {  // Если нет правой ветви, то просто заменяем элемент на тот, что слева.
                count = rmnode->count;
                node->right = rmnode->left;
                delete rmnode;
                return count;
            }
            // Дописать удаление :(
        }
        if (res > 0) { // Если наше слово МЕНЬШЕ чем в узле, то идем влево
            if (node->left == nullptr) return 0;  // Если слева числа нет, то капут. Нет такого элемента!
            if (node->left->word == word) rmnode = node->left;  // Если следующий элемент совпадает, то делаем на него ссылку
            else return removeElement(word, node->left);  // Иначе рекурсивно идем влево
        }
    }
    
    return count;  // Возвращаем количество удаленных слов
}

void Tree::setCount(const string word, const int count) {
    return;
}

// Лаба в разработке
TreeNode::~TreeNode() {
    left = right = nullptr;
    delete left, right;
}
