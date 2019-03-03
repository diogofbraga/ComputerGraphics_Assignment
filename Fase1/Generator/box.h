#ifndef BOX_H
#define BOX_H
#endif

#include <iostream>
#include <fstream>

/**
*  @brief Função que gera o pontos para a realização dos devidos triângulos, e
* conseguentemente gravação em ficheiro.
*
*  @param xdim - parâmetro que é o tamanho da dimensão X.
*	 @param ydim - parâmetro que é o tamanho da dimensão Y.
*  @param zdim - parâmetro que é o tamanho da dimensão Z.
*  @param div - parâmetro que é o números de divisões na box.
*  @param file_name - parâmetro que é o nome do ficheiro onde se devem gravar os
* pontos e triangulos gerados.
*
*/
int generateBox(float xdim, float ydim, float zdim, int div, string file_name){
	std::vector<Point> points;

	float tam_x = xdim / div;
	float tam_y = ydim / div;
	float tam_z = zdim / div;

	float z = zdim/2;
	// faces paralelas a XY
	for(int i = 0; i < div ; i++){
		float x = -(xdim/2);
		for(int j = 0 ; j < div ; j++){
			points.push_back(Point((x+tam_x),(i+1)*tam_y,z));
			points.push_back(Point(x,i*tam_y,z));
			points.push_back(Point((x+tam_x),i*tam_y,z));

			points.push_back(Point(x,(i+1)*tam_y,z));
			points.push_back(Point(x,i*tam_y,z));
			points.push_back(Point((x+tam_x),(i+1)*tam_y,z));

			points.push_back(Point((x+tam_x),(i+1)*tam_y,-z));
			points.push_back(Point((x+tam_x),i*tam_y,-z));
			points.push_back(Point(x,i*tam_y,-z));

			points.push_back(Point(x,(i+1)*tam_y,-z));
			points.push_back(Point((x+tam_x),(i+1)*tam_y,-z));
			points.push_back(Point(x,i*tam_y,-z));
			x+=tam_x;
		}
	}

	float x = xdim/2;
	// faces paralelas a ZY
	for(int i = 0; i < div ; i++){
		float z = zdim/2;
		for(int j = 0 ; j < div ; j++){
			points.push_back(Point(x,(i+1)*tam_y,(z-tam_z)));
			points.push_back(Point(x,i*tam_y,z));
			points.push_back(Point(x,i*tam_y,(z-tam_z)));

			points.push_back(Point(x,(i+1)*tam_y,z));
			points.push_back(Point(x,i*tam_y,z));
			points.push_back(Point(x,(i+1)*tam_y,(z-tam_z)));

			points.push_back(Point(-x,(i+1)*tam_y,(z-tam_z)));
			points.push_back(Point(-x,i*tam_y,(z-tam_z)));
			points.push_back(Point(-x,i*tam_y,z));

			points.push_back(Point(-x,(i+1)*tam_y,z));
			points.push_back(Point(-x,(i+1)*tam_y,(z-tam_z)));
			points.push_back(Point(-x,i*tam_y,z));
			z-=tam_z;
		}
	}

	z = zdim/2;
	// faces paralelas a ZX
	for(int i = 0; i < div ; i++){
		x = -(xdim/2);
		float y = ydim;
		for(int j = 0 ; j < div ; j++){
			points.push_back(Point((x+tam_x),y,(z-tam_z)));
			points.push_back(Point(x,y,z));
			points.push_back(Point((x+tam_x),y,z));

			points.push_back(Point(x,y,(z-tam_z)));
			points.push_back(Point(x,y,z));
			points.push_back(Point((x+tam_x),y,(z-tam_z)));

			points.push_back(Point((x+tam_x),0,(z-tam_z)));
			points.push_back(Point((x+tam_x),0,z));
			points.push_back(Point(x,0,z));

			points.push_back(Point(x,0,(z-tam_z)));
			points.push_back(Point((x+tam_x),0,(z-tam_z)));
			points.push_back(Point(x,0,z));
			x+=tam_x;
		}
		z-=tam_z;
	}


	// necessário operações sobre ficheiros
	ofstream file ("../Generated_Models/" + file_name);
		if (file.is_open()){

		// no inicio escrevem-se o numero de triangulos existente no ficheiro
		int num_points = points.size();
			file << to_string(num_points / 3) + "\n";

		// escrita dos pontos no ficheiro
		for(int i = 0 ; i < num_points ; i++){
			Point temp = points[i];
			file << to_string(temp.getX()) + " " +
					to_string(temp.getY()) + " " +
					to_string(temp.getZ()) + "\n";
		}
			file.close();
		return 1;
		} else return 0;
}
