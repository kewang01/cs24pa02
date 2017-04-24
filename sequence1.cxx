#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
  const size_type CAPACITY;

  sequence::sequence(){
    used=0;
  }

  void sequence:: start(){
    assert(used!=0);
    assert(used>30);
    current_index=0;
  }

  void sequence::advance(){
    assert(is_item()==true);
    if(current_index==used-1){
      return 0;
    }
    else{
      current_index++;
    }
  }

  void sequence::insert(const value_type& entry){
    assert(size()<CAPACITY);
    if(is_item()==false){
      for(int i=used;i>0;i--){
	data[i]=data[i-1];
      }
      data[0]=entry;
      used++;
    }
    else{
      for(int i=used;i>current_index;i--){
	data[i]=data[i-1];
      }
      data[cureent_index]=entry;
      used++;
    }
  }

  void sequence::attach(const value_type& entry){
    assert(size()<CAPACITY);
    if(is_item==false){
      data[used]=entry;
      used++;
    }
    else{
      for(int i=used;i>current_index+1;i--){
	data[i]=data[i-1];
      }
      data[current_index+1]=entry;
      used++;
    }
  }

  void sequence::remove_current()
    
      
  
