//! [code]

#include "Box.h"
#define GLM_FORCE_SWIZZLE
#include "BoxSet.h"
#include <fstream>
using namespace std;
#include "Material.h"

int main(int argc,char *argv[]) {
    BoxSet bset;
    ofstream outStream("output.txt");
    util::Material mat;
    mat.setAmbient(1,1,1);
    mat.setDiffuse(1,1,1);
    mat.setSpecular(1,1,1);
    mat.setShininess(10);
    //start with one box
    bset.add(Box(0,0,0,100,400,50));
    bset.add(Box(200,0,100,100,100,50));
    bset.add(Box(-200,0,100,100,100,50));
    bset.add(Box(150,0,50,100,200,50));
    bset.add(Box(-150,0,50,100,200,50));
    bset.add(Box(200,0,-100,100,100,50));
    bset.add(Box(-200,0,-100,100,100,50));
    bset.add(Box(150,0,-50,100,200,50));
    bset.add(Box(-150,0,-50,100,200,50));
    bset.add(Box(-100,0,0,100,300,50));
    bset.add(Box(100,0,0,100,300,50));
    bset.add(Box(25,400,0,50,100,50));
    bset.add(Box(35,500,20,20,70,20));


    
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            bset.difference(Box(210+30*(i),10+30*(j),140,20,20,20));
            bset.difference(Box(30*(i)-190,10+30*(j),140,20,20,20));
            bset.difference(Box(210+30*(i),10+30*(j),-100,20,20,20));
            bset.difference(Box(30*(i)-190,10+30*(j),-100,20,20,20));
        }
    }

    for (int i=0;i<3;i++) {
        for (int j=3;j<6;j++) {
            bset.difference(Box(160+30*(i),10+30*(j),90,20,20,20));
            bset.difference(Box(30*(i)-140,10+30*(j),90,20,20,20));
            bset.difference(Box(160+30*(i),10+30*(j),-50,20,20,20));
            bset.difference(Box(30*(i)-140,10+30*(j),-50,20,20,20));
           
        }
    }

  

    //write it out to the above file. Using the one-argument version of 
    //this function means it will export the scene graph with each box
    //of a different random color. When we incorporate lighting into the 
    //scene you should regenerate your model using a specific material,
    //by using the two-argument version of this function
    bset.toScenegraph(outStream);

}



//! [code]
