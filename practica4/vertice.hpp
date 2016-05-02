#ifndef __VERTICE_HPP__
#define __VERTICE_HPP__

#include <iostream>
using std::string;

namespace ed{
	class Vertice{
		private:
			string data_;			//datos con el nombre de la ciudad
			int label_;				//etiqueta con el número de la ciudad
		public:
			inline const string getData() const { return data_; }
			inline const int getLabel() const { return label_; }

			inline void setData(string data){ data_ = data; }
			inline void setLabel(int label){ label_ = label; }

			inline const bool operator==(const Vertice &V){ return getData() == V.getData(); }
			inline const bool operator!=(const Vertice &V){ return getData() != V.getData(); }

	};
}

#endif