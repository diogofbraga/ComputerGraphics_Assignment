#ifndef GEOMETRY_H
#define GEOMETRY_H
#endif

#include <vector>
#include <string>

using namespace std;

namespace geometry{

    /**
    * @brief classe que define intancias de Ponto
    */
    class Point{
        public:
            float x,y,z;
    };

    /**
    * @brief classe que define intancias de Translações
    */
    class Translation{
        public:
            Translation() :empty(true) {}
            bool empty;
            float time;
            vector<Point> points;
    };

    /**
    * @brief classe que define intancias de Rotaçoes
    */
    class Rotation{
        public:
            Rotation() :empty(true), angle(-1), time(-1) {}
            bool empty;
            float angle,x,y,z,time;
    };

    /**
    * @brief classe que define intancias de Escalas
    */
    class Scale{
        public:
            Scale() :empty(true) {}
            bool empty;
            float x,y,z;
    };

    /**
    * @brief classe que define intancias de Cor
    */
    class Color{
        public:
            float r,g,b;
    };

    /**
    * @brief classe que define intancias de Figura
    */
    class Figure{
        public:
            string name;
            int num_triangles;
            vector<Point> points;
            Translation translation;
            Rotation rotation;
            Scale scale;
            Color color;
    };

    /**
    * @brief classe que define intancias de Arvores
    */
    class Tree{
        public:
            Figure head_figure;
            vector<Tree> children;
    };

}
