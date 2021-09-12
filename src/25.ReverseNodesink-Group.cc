#include "headers.h"

class Solution
{
public:
    ListNode *reverseLists(ListNode *head, int k)
    {
        // 1 2 3 4 5

        ListNode *end = head;
        ListNode *start = head;
        for (int i = 0; i < k; ++i)
        {
            if (end.next != nullptr)
            {
                end = end.next;
            }
            else
            {
                return head;
            }
        }
        //k = 3
        //0    1   2   3   4   5
        //start
        //      n1  n2 end
        ListNode *n1 = head.next;
        ListNode *n2 = head.next.next;
        for (int i = 0; i < k - 1; ++i)
        {
            ListNode *tmp = n2.next;
            n2.next = n1;
            n1 = n2;
            n2 = tmp;
        }
        head.next = n2;
        n1.next return head.next;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur != nullptr)
        {
            cur = reverseLists(cur, k);
        }
        return dummy.next;
    }
};

TEST(reverseKGroup, reverseKGroup_1)
{
    Solution s;
    List l1 = {1, 2, 3, 4, 5};
    int k = 2;
    List ans = {2, 1, 4, 3, 5};
    print_list(ans.head);
    EXPECT_EQ(s.reverseKGroup(l1.head, k), ans.head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}