#include "headers.h"

class Solution
{
public:
    ListNode *MergeTwoSortedLists(ListNode *l1, ListNode *l2)
    {
        ListNode *Dummy = new ListNode(0);
        ListNode *cur = Dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = new ListNode(l1->val);

                l1 = l1->next;
            }
            else
            {
                cur->next = new ListNode(l2->val);

                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1)
        {
            cur->next = l1;
        }
        if (l2)
        {
            cur->next = l2;
        }
        return Dummy->next;
    }
};

TEST(MergeTwoSortedLists, MergeTwoSortedLists_1)
{
    Solution s;
    List l1{1, 2, 4};
    List l2{1, 3, 4};
    List ans{1, 1, 2, 3, 4, 4};
    EXPECT_EQ(s.MergeTwoSortedLists(l1.head, l2.head), ans.head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}