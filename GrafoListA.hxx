# include "GrafoListA.h"

template <class T, class U>
class Grafo {
private:
	std::vector<T> vertices;
	std::vector< std::list< pair<int,U> > > aristas;
public:
	Grafo();
	void setVertices(std::vector<T> v){
    
  }

	void setAristas(std::vector< std::list< pair<int,U> > > a);
	std::vector<T> getVertices();
	std::vector< std::list< pair<int,U> > > getAristas();
	int cantVertices() { return vertices.size(); }
	int cantAristas() {
		int suma = 0;
		for (int i = 0; i < cantVertices(); i++) {
			suma += aristas[i].size();
		}
		return suma;
	}
	int buscarVertice(T vert) {
		int ind = -1;
		for (int i = 0; i < cantVertices(); i++) {
			if (vertices[i] == vert)  ind = i;
		}
		return ind;
	}
	bool insertarVertice(T vert) {
		bool res = false;
		if (buscarVertice(vert) == -1) {
			vertices.push_back(vert);
			std::list< pair<int,U> > *nlist = new std::list< pair<int,U> >;
			aristas.push_back(*nlist);
		}
		return res;
	}
	bool insertarArista(T ori, T des, U cos) {
		bool res = false;
		int i_ori = buscarVertice(ori);
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			bool esta = false;
			std::list< pair<int,U> >::iterator itList = aristas[i_ori].begin();
			for (; itList != aristas[i_ori].end(); itList++) {
				if (itList->first == i_des)  esta = true;
			}
			if (!esta) {
				pair<int,U> *n_par = new pair<int,U>;
				n_par->first = i_des;
				n_par->second = cos;
				aristas[i_ori].push_back(*n_par);
				res = true;
			}
		}
		return res;
	}
	U buscarArista(T ori, T des) {
		U res = -1;
		int i_ori = buscarVertice(ori);
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			std::list< pair<int,U> >::iterator itList = aristas[i_ori].begin();
			for (; itList != aristas[i_ori].end(); itList++) {
				if (itList->first == i_des)  res = itList->second;
			}
		}
		return res;
	}
	bool eliminarVertice(T vert) {
		bool res = false;
		int i_vert = buscarVertice(vert);
		if ( i_vert != -1) {
			std::vector< std::list< pair<int,U> > >::iterator itA, posE;
			int ind = 0;
			for (itA = aristas.begin(); itA != aristas.end(); itA++, ind++) {
				if (ind == i_vert) {
					posE = itA;
				} else {
					std::list< pair<int,U> >::iterator itList, posEE;
					for (itList = itA->begin(); itList != itA->end(); itList++) {
						if (itList->first == i_vert) {
							posEE = itList;
						}
					}
					itA->erase(posEE);
				}
			}
			aristas.erase(posE);
		}
		return res;
	}
	bool eliminarArista(T ori, T des) {
		bool res = false;
		int i_ori = buscarVertice(ori);
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			std::list< pair<int,U> >::iterator itList, posE;
			for (itList = aristas[i_ori].begin(); itList != aristas[i_ori].end(); itList++) {
				if (itList->first == i_des)  posE = itList;
			}
			aristas[i_ori].erase(posE);
		}
		return res;
	}
};
