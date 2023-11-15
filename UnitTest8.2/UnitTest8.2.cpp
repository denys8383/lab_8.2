#include "pch.h"
#include "CppUnitTest.h"
#include "../Project8.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82
{
	TEST_CLASS(UnitTest82)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			wstring testString = L"Я навчаюся у Львівській Політехніці";
			size_t result1 = MaxWordLength(testString);
			Assert::AreEqual(size_t(11), result1);
			
		}
	};
}
