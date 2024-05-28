/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include <UnitTest++/UnitTest++.h>

#include "adts/BST.h"
#include "adts/list.h"
#include "linkedBST.h"
#include "linkedBSTNode.h"

using namespace std;

/**
 * This helper function will build a small BST on which we can perform
 * experiments.  We can call the methods of the BST
 * in a specific order to make sure it puts the nodes where we want them
 * (assuming, of course, that the insert and get functions work correctly).
 * Our tree will look like this:
 * @verbatim
 *         6
 *        / \
 *       /   \
 *      2     7
 *     / \     \
 *    1   4     9
 *       /
 *      3
 * @endverbatim
 * @return An example BST.  The caller is responsible for deleting this BST.
 */
LinkedBST<int, string>* makeExampleBST() {
    LinkedBST<int, string>* bst = new LinkedBST<int, string>();
    bst->insert(6, "6");
    bst->insert(2, "2");
    bst->insert(7, "7");
    bst->insert(1, "1");
    bst->insert(4, "4");
    bst->insert(9, "9");
    bst->insert(3, "3");
    bst->checkInvariants();
    return bst;
}

TEST(emptyBST) {
    LinkedBST<int, string>* bst = new LinkedBST<int, string>();
    CHECK_EQUAL(0, bst->getSize());
    CHECK(bst->isEmpty());
    bst->checkInvariants();
    delete bst;
}

TEST(exampleBST) {
    // Since we have to respect the BST interface -- we can't look
    // directly at the BST nodes -- we have to test the example BST to
    // make sure that it behaves like we'd think.  If this test fails,
    // then either the insert or the get method is broken and it's
    // hard to tell which.  The upside is that we test both the insert
    // and get functions with this test.
    LinkedBST<int, string>* bst = makeExampleBST();
    for (int i = 1; i <= 9; i++) {
        if (i != 5 && i != 8) {
            CHECK_EQUAL(to_string(i), bst->get(i));
        }
    }
    delete bst;
}

TEST(exampleBSTSize) {
    LinkedBST<int, string>* bst = makeExampleBST();
    CHECK_EQUAL(7, bst->getSize());
    CHECK(!bst->isEmpty());
    delete bst;
}
//
// // NOTE: Be sure to make frequent use of the checkInvariants method
// // which verifies that your BST contains the correct number of nodes
// // and has properly implemented the BST property.
//
// // TODO: test LinkedBST<K,V>::update
TEST(update) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->update(6, "42");
  CHECK_EQUAL("42", bst->get(6));
  CHECK(!bst->isEmpty());
  bst->checkInvariants();
  delete bst;
}

// // TODO: test LinkedBST<K,V>::contains
TEST(contains) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK(bst->contains(6)); //should be true
  CHECK(!bst->isEmpty());
  bst->checkInvariants();
  delete bst;
}

// // TODO: test LinkedBST<K,V>::remove
TEST(remove) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(2);
  CHECK_EQUAL(6, bst->getSize());
  CHECK(!bst->isEmpty());
  bst->checkInvariants();
  delete bst;
}

// // TODO: test LinkedBST<K,V>::getKeys
TEST(getKeys) {
  LinkedBST<int, string>* bst1 = makeExampleBST();
  LinkedBST<int, string>* bst2 = makeExampleBST();
  bst1->checkInvariants();
  bst2->checkInvariants();
  vector<pair<int, string>> vector1 = bst1->getItems();
  vector<int> vector2 = bst2->getKeys();
  //CHECK_EQUAL(, bst->getItems());
  for(int i = 0; i < bst1->getSize(); i++){
    CHECK_EQUAL(vector1[i].first, vector2[i]);
  }
  bst1->checkInvariants();
  bst2->checkInvariants();
  delete bst1;
  delete bst2;
}

// // TODO: test LinkedBST<K,V>::getItems
TEST(getItems) {
  LinkedBST<int, string>* bst2 = makeExampleBST();
  bst2->checkInvariants();
  vector<pair<int, string>> vector2 = bst2->getItems();
  vector<pair<int, string>> expected;
  expected.push_back(pair<int, string>(1, "1"));
  expected.push_back(pair<int, string>(2, "2"));
  expected.push_back(pair<int, string>(3, "3"));
  expected.push_back(pair<int, string>(4, "4"));
  expected.push_back(pair<int, string>(6, "6"));
  expected.push_back(pair<int, string>(7, "7"));
  expected.push_back(pair<int, string>(9, "9"));
  for(int i = 0; i < bst2->getSize(); i++){
    CHECK_EQUAL(expected[i].first, vector2[i].first);
    CHECK_EQUAL(expected[i].second, vector2[i].second);
  }
  bst2->checkInvariants();
  delete bst2;
}

// // TODO: test LinkedBST<K,V>::getHeight
TEST(getHeight) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(3, bst->getHeight());
  CHECK(!bst->isEmpty());
  bst->checkInvariants();
  delete bst;
}

// // TODO: test LinkedBST<K,V>::getMax
TEST(getMax) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(9, bst->getMaxKey());
  CHECK(!bst->isEmpty());
  bst->checkInvariants();
  delete bst;
}

// // TODO: test LinkedBST<K,V>::getMin
TEST(getMin) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(1, bst->getMinKey());
  CHECK(!bst->isEmpty());
  bst->checkInvariants();
  delete bst;
}
//
TEST(examplePreOrderTraversal) {
    LinkedBST<int, string>* bst = makeExampleBST();
    vector<pair<int, string>> traversal = bst->traversePreOrder();

    // build vector containing what the ordering should be
    vector<pair<int, string>> expected;
    expected.push_back(pair<int, string>(6, "6"));
    expected.push_back(pair<int, string>(2, "2"));
    expected.push_back(pair<int, string>(1, "1"));
    expected.push_back(pair<int, string>(4, "4"));
    expected.push_back(pair<int, string>(3, "3"));
    expected.push_back(pair<int, string>(7, "7"));
    expected.push_back(pair<int, string>(9, "9"));
    REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
    for (int i = 0; i < expected.size(); i++) {
        CHECK_EQUAL(expected[i].first, traversal[i].first);
        CHECK_EQUAL(expected[i].second, traversal[i].second);
    }
    delete bst;
}

// TODO: test LinkedBST<K,V>::getInOrder
TEST(getInOrder) {
    LinkedBST<int, string>* bst = makeExampleBST();
    vector<pair<int, string>> traversal = bst->traverseInOrder();

    // build vector containing what the ordering should be
    vector<pair<int, string>> expected;
    expected.push_back(pair<int, string>(1, "1"));
    expected.push_back(pair<int, string>(2, "2"));
    expected.push_back(pair<int, string>(3, "3"));
    expected.push_back(pair<int, string>(4, "4"));
    expected.push_back(pair<int, string>(6, "6"));
    expected.push_back(pair<int, string>(7, "7"));
    expected.push_back(pair<int, string>(9, "9"));
    REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
    for (int i = 0; i < expected.size(); i++) {
        CHECK_EQUAL(expected[i].first, traversal[i].first);
        CHECK_EQUAL(expected[i].second, traversal[i].second);
    }
    delete bst;
}
// // TODO: test LinkedBST<K,V>::getPostOrder
TEST(getPostOrder) {
    LinkedBST<int, string>* bst = makeExampleBST();
    vector<pair<int, string>> traversal = bst->traversePostOrder();
    vector<pair<int, string>> expected;
    expected.push_back(pair<int, string>(1, "1"));
    expected.push_back(pair<int, string>(3, "3"));
    expected.push_back(pair<int, string>(4, "4"));
    expected.push_back(pair<int, string>(2, "2"));
    expected.push_back(pair<int, string>(9, "9"));
    expected.push_back(pair<int, string>(7, "7"));
    expected.push_back(pair<int, string>(6, "6"));
    REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
    for (int i = 0; i < expected.size(); i++) {
        CHECK_EQUAL(expected[i].first, traversal[i].first);
        CHECK_EQUAL(expected[i].second, traversal[i].second);
    }
    delete bst;
}

// // TODO: test LinkedBST<K,V>::getLevelOrder
TEST(getLevelOrder) {
    LinkedBST<int, string>* bst = makeExampleBST();
    vector<pair<int, string>> traversal = bst->traverseLevelOrder();
    vector<pair<int, string>> expected;
    expected.push_back(pair<int, string>(6, "6"));
    expected.push_back(pair<int, string>(2, "2"));
    expected.push_back(pair<int, string>(7, "7"));
    expected.push_back(pair<int, string>(1, "1"));
    expected.push_back(pair<int, string>(4, "4"));
    expected.push_back(pair<int, string>(9, "9"));
    expected.push_back(pair<int, string>(3, "3"));
    REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
    for (int i = 0; i < expected.size(); i++) {
        CHECK_EQUAL(expected[i].first, traversal[i].first);
        CHECK_EQUAL(expected[i].second, traversal[i].second);
    }
    delete bst;
}

int main() {
    return UnitTest::RunAllTests();
}
