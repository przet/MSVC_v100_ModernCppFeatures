#include "msvc_v100_algoPlay.h"
#include <algorithm>
#include <list>
#include <iostream>


bool isOdd(int i)
{
   return i%2;
}

int main()
{
	//first let's see what C++11 algos work with MSVC v100

    //------------------------------------------------------------------------------
    //C++11 Algorithms that work with MSVC v100 - non-modyfying sequence operations
    //----------------------------------------------------------------------------
	std::list<int> ls;
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_front(1);  //no reason why I did this, just to mix things up

	//----------------------
	//std::all_of
	//----------------------
	if( std::all_of(ls.begin(),ls.end(),[](int i)
			{return i%2;}))
			std::cout << "All the elements are odd numbers" << std::endl;
	else 
		std::cout << "Not all the elements are odd numbers" << std::endl;

    //Although lambdas are useful, perhaps in this case the alternative of
    // passing in a function is better, and is more self documenting...
	if( std::all_of(ls.begin(),ls.end(),isOdd))
			std::cout << "All the elements are odd numbers" << std::endl;
	else 
		std::cout << "Not all the elements are odd numbers" << std::endl;
	
	//----------------------
	//std::any_of
	//----------------------
	if( std::any_of(ls.begin(),ls.end(),[](int i)
			{return i%2;}))
			std::cout << "at least one of the elements is an odd number" << std::endl;
	else 
		std::cout << "None of the elements are odd numbers" << std::endl;
	
	//----------------------
	//std::none_of
	//----------------------
	if( std::none_of(ls.begin(),ls.end(),[](int i)
			{return i<0;}))
			std::cout << "There are no negative numbers in the list" << std::endl;
	else 
		std::cout << "There is a negative number in the list" << std::endl;
	
	//----------------------
	//std::find_if_not
	//----------------------
    auto it = std::find_if_not(ls.begin(),ls.end(),isOdd);
    std::cout << "The first even value is " << *it << std::endl;

    //A domain specific example:
    Track track1(1029), track2(786),track3(4756);
    track1.setClassification(Track::Classifcation::eFriend);
    track2.setClassification(Track::Classifcation::eFriend);
    track3.setClassification(Track::Classifcation::eUFO);
    
    std::list<Track> trackList;
    trackList.push_front(track3);
    trackList.push_front(track2);
    trackList.push_front(track1);

    auto it2 = std::find_if_not(trackList.begin(),trackList.end(),[](Track track)
        {return track.getClassification()==Track::Classifcation::eFriend;});
    if(it2 !=trackList.end())
        std::cout <<"We have a non-friendly track!" << std::endl;

    //Again, it could be argued that rather than a lambda, we could add in a function that
    // has been defined elsewhere - but if its not too tricky, then it can still be 
    //self documenting - e.g above we have" find if not track == friend, at a glance.
    //Experience in reading lamda expressions inside algorithms will help, just like
    //experience reading other code constructs does too


	//----------------------
	//std::is_permutation ...This one does NOT work with MSVC v100
	//----------------------
    //This one might not be as self-explanatory, but from cplusplus.com:
    //Compares the elements in the range defined for container 1, with those
    //in the range beginning at the start point defined for container 2,
    //returns true if all the elements in both ranges match, even in a different
    //order.
    //In otherwords, given two ranges (each belonging to a container), do we have a 
    //match, in any order.

    //Let's say we have two containers of track numbers, say maybe from two different
    //search windows, and we want to check if they are the same, e.g are the tracks
    //in the second search window exactly the same as those in the first search window.

    Track track4(786),track5(4756),track6(1029);
    

    std::list<int> trackNumberList_SearchWindow1;
    trackNumberList_SearchWindow1.push_back(track1.TrackNumber());
    trackNumberList_SearchWindow1.push_back(track2.TrackNumber());
    trackNumberList_SearchWindow1.push_back(track3.TrackNumber());

    std::list<int> trackNumberList_SearchWindow2;
    trackNumberList_SearchWindow2.push_back(track4.TrackNumber());
    trackNumberList_SearchWindow2.push_back(track5.TrackNumber());
    trackNumberList_SearchWindow2.push_back(track6.TrackNumber());

    //if (std::is_permutation(trackNumberList_SearchWindow1.begin(),
    //    trackNumberList_SearchWindow1.end(),trackNumberList_SearchWindow2.begin()))
    //    std::cout <<"both search windows have the same tracks! Engage!" << std::endl;
   

    //------------------------------------------------------------------------------
    //C++11 Algorithms that work with MSVC v100 - MODIFYING sequence operations
    //----------------------------------------------------------------------------
    
	//----------------------
	//std::copy_n
	//----------------------

    //TODO come back to make this compile
    //std::copy_n(trackNumberList_SearchWindow1,2,trackNumberList_SearchWindow2);
    //TODO assignment operation repercussions?

	//----------------------
	//std::copy_if
	//----------------------
    auto &tNLSW1 = trackNumberList_SearchWindow1;   
    auto &tNLSW2 = trackNumberList_SearchWindow2; //got sick of writing the long names.
                                                  //another good use of auto - I don't need
                                                  // to remember the type

    std::list<int> trackNumberFinalList;
    trackNumberFinalList.resize(tNLSW2.size());
    auto it3 = std::copy_if(tNLSW2.begin(),tNLSW2.end(),trackNumberFinalList.begin(),
        [](int trackNumber){return trackNumber > 1000;});
    trackNumberFinalList.resize(std::distance(trackNumberFinalList.begin(),it3));
    std::cout.setf(std::ios_base::boolalpha);
    std::cout<< "It is "<<(trackNumberFinalList.size() == 2)<<
        " that list is of size 2" <<std::endl;

    std::cout<< "It is "<<(trackNumberFinalList.front() == track5.TrackNumber())<<
        " that the first element of trackNumberFinal list is " << track5.TrackNumber()
        <<std::endl;
    
    
    //----------------------
	//std::move and std::move_backward
	//----------------------
    

    //std::shuffle NO

    
    
     //------------------------------------------------------------------------------
    //C++11 Algorithms that work with MSVC v100 - Partitions
    //----------------------------------------------------------------------------
    
    //----------------------
	//std::is_partitioned
	//----------------------

    
    //----------------------
	//std::partition_copy
	//----------------------

    //----------------------
	//std::partition_point
	//----------------------
   
     //------------------------------------------------------------------------------
    //C++11 Algorithms that work with MSVC v100 - Sorting
    //----------------------------------------------------------------------------
    

    //----------------------
	//std::is_sorted
	//----------------------

    
    //----------------------
	//std::is_sorted_until
	//----------------------
	
     //------------------------------------------------------------------------------
    //C++11 Algorithms that work with MSVC v100 - Heap
    //----------------------------------------------------------------------------


    //----------------------
	//std::is_heap and std::is_heap_until
	//----------------------


     //------------------------------------------------------------------------------
    //C++11 Algorithms that work with MSVC v100 - Min/Max
    //----------------------------------------------------------------------------

    //----------------------
	//std::minmax and std::minmax_element
	//-------------------

    



	//!Bad security practice, don't do this!
	system("pause");
	return 0;
}