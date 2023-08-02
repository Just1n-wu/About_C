# include "QFMutableArray.hpp"
# include "QFMutableList.hpp"

void test_1()
{
	QFMutableArray<int>* mutableArray = new QFMutableArray<int>();

	// test
	for (int i = 0; i < 10; i++)
		mutableArray->add(i);

	mutableArray->add(3, 100);
	mutableArray->add(3, 100);

	cout << mutableArray->remove(3) << endl;

	cout << mutableArray->index(100) << endl;

	cout << mutableArray->removeElement(100) << endl;

	cout << mutableArray->set(3, 100) << endl;

	cout << mutableArray->get(3) << endl;

	// ÈÝÆ÷ÔªËØ±éÀú
	for (int i = 0; i < mutableArray->length(); i++)
		cout << mutableArray->get(i) << " ";

	cout << endl;

	mutableArray->sort();

	cout << mutableArray->str() << endl;
}

void test_2()
{
	QFMutableList<int>* list = new QFMutableList<int>();

	for (int i = 0; i < 10; i++)
		list->add(i);

	list->add(10, 1000);
	list->add(0, 100);
	list->add(5, 500);

	cout << list->remove(5) << endl;
	cout << list->removeElement(100) << endl;
	cout << list->removeElement(1000) << endl;

	cout << list->set(3, 300) << endl;
	cout << list->get(3) << endl;

	// list->clear();

	cout << list->length() << endl;

	list->sort();

	cout << list->str() << endl;

}

int main()
{
	test_1();
	cout << "----------------------------------------------" << endl;
	test_2();

	return EXIT_SUCCESS;
}