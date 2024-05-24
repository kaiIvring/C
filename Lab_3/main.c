#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义树节点结构
typedef struct TreeNode 
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 定义线索二叉树节点结构
typedef struct ThreadedTreeNode 
{
    char val;
    struct ThreadedTreeNode* left;
    struct ThreadedTreeNode* right;
    int ltag; // 0 表示左孩子，1 表示前驱
    int rtag; // 0 表示右孩子，1 表示后继
} ThreadedTreeNode;

//创建普通二叉树节点
TreeNode* createNode(char val)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 创建线索二叉树节点
ThreadedTreeNode* createThreadedTreeNode(char val)
{
    ThreadedTreeNode* newNode = (ThreadedTreeNode*)malloc(sizeof(ThreadedTreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->ltag = 0;
    newNode->rtag = 0;
    return newNode;
}

// 解析括号表示法并创建树
TreeNode* parseTree(const char** str)
{
    // 如果当前字符是字符串结束符或逗号，则返回 NULL
    if (**str == '\0' || **str == ',')
    {
        return NULL;
    }

    // 创建一个新节点，其值为当前字符
    TreeNode* node = createNode(**str);
    // 移动到下一个字符
    (*str)++;

    // 如果下一个字符是左括号 '('，则表示有子树
    if (**str == '(')
    {
        (*str)++; //跳过 '('

        //递归解析左子树
        node->left = parseTree(str);

        //如果左子树之后有逗号，则表示还有右子树
        if (**str == ',')
        {
            (*str)++;
            // 递归解析右子树
            node->right = parseTree(str);
        }

        // 跳过右括号 ')'
        if (**str == ')')
        {
            (*str)++;
        }
    }
    return node;
}


// 凹入表示法的递归函数
void printIndented(TreeNode* root, int level)//level表示当前节点的层次
{
    if (root == NULL)
    {
        return;
    }

    // 打印当前节点
    for (int i = 0; i < level; i++)
    {
        printf("--");
    }
    printf("%c\n", root->val);

    // 递归打印左子树和右子树
    printIndented(root->left, level + 1);
    printIndented(root->right, level + 1);
}

// 查找某节点的左、右孩子节点值
void findChildren(TreeNode* root, char target)
{
    if (root == NULL)
    {
        return;
    }

    //找到目标节点
    if (root->val == target)
    {
        if (root->left != NULL)
        {
            printf("Left child of %c: %c\n", target, root->left->val);
        }
        else
        {
            printf("%c has no left child\n", target);
        }
        if (root->right != NULL)
        {
            printf("Right child of %c: %c\n", target, root->right->val);
        }
        else
        {
            printf("%c has no right child\n", target);
        }
    }
    
    //递归查找左右子树
    findChildren(root->left, target);
    findChildren(root->right, target);
}

// 计算二叉树的高度
int treeHeight(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    //递归计算左右子树的高度
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    //返回左右子树中较大的高度加1，即为树的高度
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 释放树的内存
void freeTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    //释放流程
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 获取先序序列
void getPreOrder(TreeNode* root, char* preOrder, int* index)
{
    if (root == NULL)
    {
        return;
    }
    //获取先序序列的顺序为：根节点->左子树->右子树
    preOrder[(*index)++] = root->val;
    getPreOrder(root->left, preOrder, index);
    getPreOrder(root->right, preOrder, index);
}

// 获取中序序列
void getInOrder(TreeNode* root, char* inOrder, int* index)
{
    if (root == NULL)
    {
        return;
    }
    //获取中序序列的顺序为：左子树->根节点->右子树
    getInOrder(root->left, inOrder, index);
    inOrder[(*index)++] = root->val;
    getInOrder(root->right, inOrder, index);
}

// 根据先序和中序序列重建二叉树 用const修饰preOrder和inOrder，不希望其值被修改
TreeNode* buildTreeFromPreInOrder(const char* preOrder, const char* inOrder, int start, int end, int* preIndex)
{
    if (start > end)
    {
        return NULL;
    }

    //创建新节点，其值为先序序列的当前值
    TreeNode* newNode = createNode(preOrder[*preIndex]);
    (*preIndex)++;

    if (start == end)
    {
        return newNode;
    }

    int inIndex;//中序序列的下标
    //在中序序列中找到当前节点的位置,即为左右子树的分界点
    //每一次递归都是一样的，就是为了找到中间节点，然后递归构建左右子树
    for (inIndex = start; inIndex <= end; inIndex++)
    {
        if (inOrder[inIndex] == newNode->val)
        {
            break;
        }
    }
    //递归构建左右子树
    //左子树的范围为start到inIndex-1,右子树的范围为inIndex+1到end
    newNode->left = buildTreeFromPreInOrder(preOrder, inOrder, start, inIndex - 1, preIndex);
    newNode->right = buildTreeFromPreInOrder(preOrder, inOrder, inIndex + 1, end, preIndex);
    return newNode;
}

//将普通二叉树转换为线索二叉树
ThreadedTreeNode* createThreadedTree(TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    //递归遍历普通二叉树将其转换为线索二叉树
    ThreadedTreeNode* newNode = createThreadedTreeNode(root->val);
    newNode->left = createThreadedTree(root->left);
    newNode->right = createThreadedTree(root->right);
    return newNode;
}

//中序线索化
void inOrderThreading(ThreadedTreeNode* root, ThreadedTreeNode** pre)
{
    if (root == NULL)
    {
        return;
    }

    // 递归处理左子树
    inOrderThreading(root->left, pre);

    // 如果当前节点没有左孩子，则将左指针指向前驱节点，并设置左线索标志
    if (root->left == NULL)
    {
        root->left = *pre;
        root->ltag = 1;
    }

    // 如果前驱节点的右孩子为空，则将其右指针指向当前节点，并设置右线索标志
    if (*pre != NULL && (*pre)->right == NULL)
    {
        (*pre)->right = root;
        (*pre)->rtag = 1;
    }

    // 更新前驱节点
    *pre = root;

    // 递归处理右子树
    inOrderThreading(root->right, pre);
}


// 采用非递归方式遍历输出中序线索二叉树的中序序列
void inOrderTraversal(ThreadedTreeNode* root)
{
    ThreadedTreeNode* current = root;
    //结点不为空循环
    while (current != NULL)
    {
        //只有当ltag为0时，current指向的是左孩子，所以找到最左下结点
        while (current->ltag == 0)
        {
            current = current->left;
        }
        printf("%c ", current->val);
        //当rtag为1时，current指向的是后继结点，则继续输出后继结点
        while (current->rtag == 1 && current->right != NULL)
        {
            current = current->right;
            printf("%c ", current->val);
        }
        //current指向的是右孩子，继续输出右孩子
        current = current->right;
    }
}

// 输出树的括号表示法
void printBracketNotation(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%c", root->val);//输出根节点的值

    //如果左右子树有一个不为空，就能输出左右括号
    if (root->left != NULL || root->right != NULL)
    {
        printf("(");
        printBracketNotation(root->left);
        //右子树不为空
        if (root->right != NULL)
        {
            printf(",");
            printBracketNotation(root->right);
        }
        printf(")");
    }
}

void menu() 
{
    printf("--------二叉树基本操作演示--------\n");
    printf("1. 从括号表示法创建二叉树\n");
    printf("2. 查找'H'节点的左、右孩子节点值\n");
    printf("3. 计算二叉树的高度\n");
    printf("4. 获取先序序列\n");
    printf("5. 获取中序序列\n");
    printf("6. 释放二叉树\n");
    printf("7. 重构二叉树并输出括号表达式\n");
    printf("8. 中序线索化并输出中序线索二叉树的中序序列\n");
    printf("9. 退出\n");
}

int option()
{
    int op;
    printf("请选择操作：\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    TreeNode* b = NULL;//二叉树根节点b
    char preOrder[100] = { 0 };//先序序列
    char inOrder[100] = { 0 };//中序序列
    while (1)
    {
        menu();
        int choice = option();
        switch (choice)
        {
        case 1: //由括号表示法创建二叉树
        {
            system("cls");

            // 从用户输入获取括号表示法
            char str[100];
            printf("Enter the tree in bracket notation: \n");
            getchar(); // 消耗掉换行符
            fgets(str, sizeof(str), stdin);//从标准输入读取字符串，并储存在str数组中

            // 去掉换行符
            size_t len = strlen(str);
            if (len > 0 && str[len - 1] == '\n')
            {
                str[len - 1] = '\0';
            }

            // 创建对应的二叉树
            const char* p = str;//不希望str的值被修改，所以用const修饰
            b = parseTree(&p);

            // 输出二叉树（采用凹入表示法）
            printf("Indented representation of tree:\n");
            printIndented(b, 0);

            // 暂停
            system("pause");
            system("cls");
            break;
        }

        case 2://输出 'H' 结点的左、右孩子结点值
        {
            system("cls");
            if (b != NULL)
            {
                printf("Children of node 'H':\n");
                findChildren(b, 'H');
            }
            else
            {
                printf("\nTree is not created yet.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 3://输出二叉树的高度
        {
            system("cls");
            if (b != NULL)
            {
                int height = treeHeight(b);
                printf("Height of tree: %d\n", height);
            }
            else
            {
                printf("Tree is not created yet.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 4://获取并输出先序序列
        {
            system("cls");
            if (b != NULL)
            {
                int preIndex = 0;//先序序列的下标
                getPreOrder(b, preOrder, &preIndex);
                preOrder[preIndex] = '\0';//补上字符串结束符
                printf("Pre-order sequence: %s\n", preOrder);
            }
            else
            {
                printf("Tree is not created yet.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 5://获取并输出中序序列
        {
            system("cls");
            if (b != NULL)
            {
                int inIndex = 0;
                getInOrder(b, inOrder, &inIndex);
                inOrder[inIndex] = '\0';
                printf("In-order sequence: %s\n", inOrder);
            }
            else
            {
                printf("Tree is not created yet.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 6://释放原二叉树
        {
            system("cls");
            if (b != NULL)
            {
                freeTree(b);
                b = NULL;//置二叉树根节点b为空
                printf("Tree freed\n");
            }
            else
            {
                printf("Tree is not created yet.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 7://利用先序序列和中序序列重新构造二叉树并以括号表示法输出
        {
            system("cls");
            if (preOrder[0] != '\0' && inOrder[0] != '\0')
            {
                int preIndex = 0;//先序序列的下标

                //函数中的start和end分别对应0和strlen(inOrder) - 1，即中序序列的起始和结束位置
                TreeNode* rebuiltTree = buildTreeFromPreInOrder(preOrder, inOrder, 0, strlen(inOrder) - 1, &preIndex);

                // 输出重新构造的二叉树的括号表示法
                printf("Bracket notation of rebuilt tree:\n");
                printBracketNotation(rebuiltTree);
                printf("\n");

                // 释放重新构造的树
                freeTree(rebuiltTree);
            }
            else
            {
                printf("Please generate pre-order and in-order sequences first.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 8://对二叉树进行线索化并输出中序序列
        {
            system("cls");
            if (preOrder[0] != '\0' && inOrder[0] != '\0')
            {
                // 利用先序序列和中序序列重新构造二叉树
                int preIndex = 0;//先序序列下标
                TreeNode* rebuiltTree = buildTreeFromPreInOrder(preOrder, inOrder, 0, strlen(inOrder) - 1, &preIndex);

                //创建线索二叉树
                ThreadedTreeNode* threadedTree = createThreadedTree(rebuiltTree);
                //前驱节点
                ThreadedTreeNode* pre = NULL;
                //中序线索化
                inOrderThreading(threadedTree, &pre);

                //非递归方式遍历输出中序线索二叉树的中序序列
                printf("In-order traversal of threaded tree:\n");
                inOrderTraversal(threadedTree);
                printf("\n");

                freeTree(rebuiltTree);
            }
            else
            {
                printf("\nPlease generate pre-order and in-order sequences first.\n");
            }
            system("pause");
            system("cls");
            break;
        }

        case 9:
        {
            // 退出程序
            return 0;
        }

        default:
        {
            printf("\nInvalid option. Please try again.\n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    return 0;
}
