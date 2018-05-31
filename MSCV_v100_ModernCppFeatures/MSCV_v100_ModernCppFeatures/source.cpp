#include <list>
#include <algorithm>
#include <iostream>


int main()
{
	//---------------------------
	//keyword auto
	//---------------------------
	std::list<int> ls;
	ls.push_back(1); ls.push_back(2); ls.push_back(3);

	//instead of....
	std::list<int>::iterator it;
	for (it = ls.begin(); it !=ls.end();++it)
		std::cout << *it << std::endl;

	//can do this...
	for(auto it = ls.begin();it !=ls.end();++it)
		std::cout <<*it << std::endl;

	//advantage...don't need to waste brain space thinking about what the list holds,
	//or that is even a list (in this case at least) - less imperative and more declrative
	//(that is more "what to do", less "how to do it"). 

	//const auto issues (Barney)
	//for (const auto it = ls.begin();it!=ls.end();++it)
	//	std::cout << *it << std::endl;
	//But isn't this always an issue??

	//---------------------------------

	//-----------------------------------
	//lamdas
	//------------------------------------
	const int number = 400;
	std::for_each(ls.begin(),ls.end(),[number](int elem)
	{elem+=number; std::cout << elem << std::endl;});

	for(auto it = ls.begin();it !=ls.end();++it)
		std::cout <<*it << std::endl;
	//But can't do this with v100: (can in v140+) - won't compile! 
	//std::for_each(ls.begin(),ls.end(),[number](auto elem)
	//{elem+=number; std::cout << elem << std::endl;});

	//another example
	auto it2 = std::find_if(ls.begin(),ls.end(), [](int elem)
			{return elem%2==1;});

	std::cout << "The first odd value is" << *it2 << std::endl;
	

	








	//----------------------------------------



	//!Bad security practice, don't do this!
	system("pause");

	
	














	return 0;
}

