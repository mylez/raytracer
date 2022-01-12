#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__
/*
Geometry is an abstract class for a geometric object.
 A derived class of Geometry will have an implemention of
   ```void init(void)```
 or
   ```void init(const char* s).```
 The option for const char* input is for a derived class
 that requires reading external files.
 The implementation of the `init` is for initializing the
 geometry_store (i.e. setting up the buffers etc).

 The draw command is fixed.  We can call

 glBindVertexArray(obj.vao);
 glDrawElements(obj.mode, obj.count, obj.type, 0);

which should explain the purpose of those class members.
 We can also just call the "draw()" member function, which
 is equivalent to the commands above.

The array of buffers is encapsulated in std::vector so
we do not need to manually allocate/free the memory for
arrays of unknown size.
*/

#include <vector>

#include "Ray.h"

class Geometry {
public:
    //GLenum mode = GL_TRIANGLES; // the cookboook for glDrawElements
    int count = 0; // number of elements to draw
    //GLenum type = GL_UNSIGNED_INT; // type of the index array
    //GLuint vao; // vertex array object a.k.a. geometry_store spreadsheet
    //std::vector<GLuint> buffers; // data storage
    
    virtual void init() {};
    virtual void init(const char *) {};

    /**
     * This virtual function is inherited by subclasses of Geometry, in order to
     * accomodate for specific geometry types (i.e. simple spheres vs mesh objects).
     *
     * @param ray
     * @param modelview
     * @param pos (output parameter)
     * @param norm (output parameter)
     *
     * @return true if an intersection exists, otherwise false.
     *
     * @author Miles
     */
    virtual bool do_intersect(Ray, glm::mat4, glm::vec3 &, glm::vec3 &) {
        return false;
    }

/*
    void draw(void){
        //glBindVertexArray(vao);
        //glDrawElements(mode,count,type,0);
    }
*/

    virtual ~Geometry() = default;
};

#endif 
