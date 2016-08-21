
#ifndef DB_ELEMENTS_HPP
#define DB_ELEMENTS_HPP

// forward declarations
//class Element;
class DB_Nodes;
class DB_Parts;
class FEMFile;

// includes
#include <vector>
#include <map>
#include "Element.hpp"

using namespace std;

class DB_Elements {

private:
  FEMFile* femfile;
  DB_Nodes* db_nodes;
  DB_Parts* db_parts;
  map<int,Element*> elements2;
  map<int,Element*> elements4;
  map<int,Element*> elements8;
  map<int,Element*> elements2ByIndex;
  map<int,Element*> elements4ByIndex;
  map<int,Element*> elements8ByIndex;

public:
  DB_Elements(FEMFile* _femfile);
  ~DB_Elements();
  FEMFile* get_femfile();
  DB_Nodes* get_db_nodes();
  Element* add_element_byIndex(ElementType _eType,int _id,vector<int> _elem_data);
  //Element* add_element_byID(ElementType _eType,int _id, int _partid, vector<int> _node_ids)
  Element* add_element_byKeyFile(ElementType _eType,int _id, int _partid, vector<int> _node_ids);

  size_t size(); 
  Element* get_elementByID(int _eType, int _id);
  Element* get_elementByIndex(int _eType, int _index);

};

#endif