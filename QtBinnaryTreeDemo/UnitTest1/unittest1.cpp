#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\QtBinnaryTreeDemo\BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntTreeTests
{		
	class BTint : public BinarySearchTree<int> {
		
	};

	TEST_CLASS(PushAndReadElementsBinaryTree)
	{
	public:
		BTint Tree;
		int value = 0;
		string name = "";
		TEST_METHOD(SimplePushTest1)
		{
			Tree.push(5);
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
		}
		TEST_METHOD(SimplePushTest2)
		{
			Tree.push(5);
			Tree.GetValueByPosition("N", value, name);
			Assert::AreEqual(value, 5);
		}
		TEST_METHOD(SimplePushTest3)
		{
			Tree.push(5);
			Tree.GetValueByPosition("N", value, name);
			Assert::AreEqual(string("A"), name);
		}
		TEST_METHOD(GetValueByPositionTest1) {
			Assert::IsFalse(Tree.GetValueByPosition("N", value, name));
		}
		TEST_METHOD(GetValueByPositionTest2) {
			Tree.push(5);
			Assert::IsFalse(Tree.GetValueByPosition("NL", value, name));
		}
		TEST_METHOD(GetValueByPositionTest3) {
			Tree.push(5);
			Assert::IsFalse(Tree.GetValueByPosition("X", value, name));
		}
		TEST_METHOD(GetValueByPositionTest4) {
			Tree.push(5);
			Assert::IsFalse(Tree.GetValueByPosition("XR", value, name));
		}
		TEST_METHOD(GetValueByPositionTest5) {
			Tree.push(5);
			Tree.push(6);
			Assert::IsFalse(Tree.GetValueByPosition("XR", value, name));
		}
		TEST_METHOD(GetValueByPositionTest6) {
			Tree.push(5);
			Tree.push(6);
			Assert::IsTrue(Tree.GetValueByPosition("NR", value, name));
		}
		TEST_METHOD(SimplePushTest4)
		{
			Tree.push(5);
			Tree.push(6);
			Tree.GetValueByPosition("NR", value, name);
			Assert::AreEqual(value, 6);
		}
		TEST_METHOD(SimplePushTest5)
		{
			Tree.push(5);
			Tree.push(6);
			Tree.GetValueByPosition("NR", value, name);
			Assert::AreEqual(string("B"), name);
		}
		TEST_METHOD(BalanceTree3Elements)
		{
			Tree.push(5);
			Tree.push(6);
			Tree.push(7);
			Assert::AreEqual(uint(2), Tree.GetTreeHeight());
		}
		TEST_METHOD(Initialzation3Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7 };
			Assert::AreEqual(uint(2), Tree.GetTreeHeight());
		}
		TEST_METHOD(PushTest4Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,3 };
			Assert::AreEqual(uint(3), Tree.GetTreeHeight());
		}
		TEST_METHOD(PushTest5Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,3,8 };
			Assert::AreEqual(uint(3), Tree.GetTreeHeight());
		}
		TEST_METHOD(PushTest8Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,3,8,2,13,3 };
			Assert::AreEqual(uint(4), Tree.GetTreeHeight());
		}
		TEST_METHOD(PushTest14Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,3,4 ,7,8,34,21,223,2,1,56,43 };
			Assert::AreEqual(uint(4), Tree.GetTreeHeight());
		}
		TEST_METHOD(GetFromTest5Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,3,8 };
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
			Assert::AreEqual(string("B"), name);
			Assert::AreEqual(6, int(value));
		}
		
		TEST_METHOD(Add1000ElementsTest)
		{
			BTint Tree;
			for (int i = 0; i < 1000; i++)
				Tree.push(i);
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
			Assert::AreEqual(string("XO"), name);
			Assert::AreEqual(413, int(value));
		}
	};
	TEST_CLASS(RemoveElementsInBinaryTree) {
		int value = 0;
		string name = "";
		TEST_METHOD(RemoveRoot5Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,3,8 };
			Tree.remove(6, "B");
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
			Assert::AreEqual(string("A"), name);
			Assert::AreEqual(5, int(value));
		}
		TEST_METHOD(RemoveRootWithBalance4Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,7,8 };
			Tree.remove(6, "B");
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
			Assert::AreEqual(string("C"), name);
			Assert::AreEqual(7, int(value));
		}
		TEST_METHOD(RemoveLowestItem4Elements)
		{
			BinarySearchTree<int> Tree{ 5,6,3,8};
			Tree.remove(3, "C");
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
			Assert::AreEqual(string("B"), name);
			Assert::AreEqual(6, int(value));
		}
		TEST_METHOD(GetRemovedElementTest)
		{
			BinarySearchTree<int> Tree{ 5,6,3,8 };
			Tree.remove(8, "D");
			Assert::IsFalse(Tree.GetValueByPosition("NRR", value, name));
		}
	};
}
namespace StringTreeTests
{
	class BTString : public BinarySearchTree<string> {

	};

	TEST_CLASS(PushAndReadElementsBinaryTree)
	{
	public:
		BTString Tree;
		string value = "";
		string name = "";
		TEST_METHOD(SimplePushTest1)
		{
			Tree.push("ala");
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
		}
		TEST_METHOD(SimplePushTest2)
		{
			Tree.push("ala");
			Tree.GetValueByPosition("N", value, name);
			Assert::AreEqual(value, string("ala"));
		}
		TEST_METHOD(SimplePushTest3)
		{
			Tree.push("ala");
			Tree.GetValueByPosition("N", value, name);
			Assert::AreEqual(string("A"), name);
		}
		TEST_METHOD(GetValueByPositionTest1) {
			Assert::IsFalse(Tree.GetValueByPosition("N", value, name));
		}
		TEST_METHOD(GetValueByPositionTest2) {
			Tree.push("ala");
			Assert::IsFalse(Tree.GetValueByPosition("NL", value, name));
		}
		TEST_METHOD(GetValueByPositionTest3) {
			Tree.push("ala");
			Assert::IsFalse(Tree.GetValueByPosition("X", value, name));
		}
		TEST_METHOD(GetValueByPositionTest4) {
			Tree.push("ala");
			Assert::IsFalse(Tree.GetValueByPosition("XR", value, name));
		}
		TEST_METHOD(GetValueByPositionTest5) {
			Tree.push("ala");
			Tree.push("ma");
			Assert::IsFalse(Tree.GetValueByPosition("XR", value, name));
		}
		TEST_METHOD(GetValueByPositionTest6) {
			Tree.push("ala");
			Tree.push("ma");
			Assert::IsTrue(Tree.GetValueByPosition("NR", value, name));
		}
		TEST_METHOD(SimplePushTest4)
		{
			Tree.push("ala");
			Tree.push("ma");
			Tree.GetValueByPosition("NR", value, name);
			Assert::AreEqual(value, string("ma"));
		}
		TEST_METHOD(SimplePushTest5)
		{
			Tree.push("ala");
			Tree.push("ma");
			Tree.GetValueByPosition("NR", value, name);
			Assert::AreEqual(string("B"), name);
		}
		TEST_METHOD(BalanceTree3Elements)
		{
			Tree.push("ala");
			Tree.push("kota");
			Tree.push("ma");
			Assert::AreEqual(uint(2), Tree.GetTreeHeight());
		}
		TEST_METHOD(Initialzation3Elements)
		{
			BinarySearchTree<string> Tree{ "ala","kota","ma" };
			Assert::AreEqual(uint(2), Tree.GetTreeHeight());
		}
		TEST_METHOD(PushTest4Elements)
		{
			BinarySearchTree<string> Tree{ "ala","kota","ma","123" };
			Assert::AreEqual(uint(3), Tree.GetTreeHeight());
		}
		TEST_METHOD(PushTest5Elements)
		{
			BinarySearchTree<string> Tree{ "ala","kota","ma","123", "zzzz" };
			Assert::AreEqual(uint(3), Tree.GetTreeHeight());
		}
		TEST_METHOD(GetFromTest5Elements)
		{
			BinarySearchTree<string> Tree{ "ala","kota","ma","123", "zzzz" };
			Assert::IsTrue(Tree.GetValueByPosition("N", value, name));
			Assert::AreEqual(string("B"), name);
			Assert::AreEqual(string("kota"), value);
		}
	};
}

namespace SerializationTests {
	TEST_CLASS(SerializationBinaryTree) {
		TEST_METHOD(ConvertFloatToString)
		{
			float type = 0.75f;
			string str = toString<float>(type);
			Assert::AreEqual(string("0.75"), str);
		}

		TEST_METHOD(ConvertStringToString)
		{
			string type = "hello world";
			string str = toString<string>(type);
			Assert::AreEqual(string("hello world"), str);
		}
		TEST_METHOD(Serializing1Element)
		{
			BinarySearchTree<string> Tree{ "ala" };
			string str = Tree.serialize();
			Assert::AreEqual(string("<name A> <value ala> "), str);
		}

		TEST_METHOD(Serializing3Elements)
		{
			BinarySearchTree<int> Tree{ 3,4,1 };
			string str = Tree.serialize();
			Assert::AreEqual(string("<name C> <value 1> <name A> <value 3> <name B> <value 4> "), str);
		}
	};
}