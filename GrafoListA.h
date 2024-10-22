

template <class T, class U>
class Grafo {
private:
	std::vector<T> vertices;
	std::vector< std::list< pair<int,U> > > aristas;
public:
	Grafo();
	void setVertices(std::vector<T> v);
	void setAristas(std::vector< std::list< pair<int,U> > > a);
	std::vector<T> getVertices();
	std::vector< std::list< pair<int,U> > > getAristas();
  int cantAristas();
  int buscarVertice(T vert);
  bool insertarVertice(T vert);
  bool insertarArista(T ori, T des, U cos);
  U buscarArista(T ori, T des);
  bool eliminarVertice(T vert);
  bool eliminarArista(T ori, T des);
};


  
