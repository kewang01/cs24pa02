#include<cassert>
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
  const sequence::size_type sequence::CAPACITY;

  sequence::sequence(){
    used=0;
  }

  void sequence:: start(){
    current_index=0;
  }

  void sequence::advance(){
    assert(is_item()==true);
    current_index++;
  }

  void sequence::insert(const value_type& entry){
    assert(size()<sequence::CAPACITY);
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
      data[current_index]=entry;
      used++;
    }
  }

  void sequence::attach(const value_type& entry){
    assert(size()<sequence::CAPACITY);
    if(is_item()==false){
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

  void sequence::remove_current(){
    assert(is_item()==true);
    for(int i=current_index;i<used-1;i++){
      data[i]=data[i+1];
    }
    used--;
  }

  sequence::size_type sequence::size() const{
    return used;
  }

  bool sequence::is_item() const{
    return (used!=0 && current_index<used);
  }

  sequence::value_type sequence::current() const{
    assert(is_item());
    return data[current_index];
  }
}
    
    
      
  
