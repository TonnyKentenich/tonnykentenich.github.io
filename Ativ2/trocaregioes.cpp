#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image, virt;	// Classe Mat a(nL, nC, CV_8U);
  Vec3b val;	// Vetores
  int larg, alt;

  image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);	// Grayscale -> matriz com tons de cinza / "unsigned char" -> "uchar" 255 bits
  if(!image.data)
    cout << "nao abriu bolhas.png" << endl;

  virt = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);	// Grayscale -> matriz com tons de cinza / "unsigned char" -> "uchar" 255 bits
  if(!virt.data)
    cout << "nao abriu bolhas.png" << endl;

  
  //virt=image;
  larg=image.size().width; 
  alt=image.size().height;

  namedWindow("janela",WINDOW_AUTOSIZE);	// Nomeando e identificando janelas

  // Construindo quadrado da diagonal final
  for(int i=0;i<alt/2;i++){
    for(int j=0;j<larg/2;j++){
      virt.at<uchar>(i+alt/2,j+larg/2)=image.at<uchar>(i,j);			// Acessando elementos unsigned.. gravando numero 0
      virt.at<uchar>(i,j)=image.at<uchar>(i+alt/2,j+larg/2);			// Acessando elementos unsigned.. gravando numero 0
      virt.at<uchar>(i,j+larg/2)=image.at<uchar>(i+alt/2,j);			// Acessando elementos unsigned.. gravando numero 0
      virt.at<uchar>(i+alt/2,j)=image.at<uchar>(i,j+larg/2);			// Acessando elementos unsigned.. gravando numero 0
    }
  }
  
  imshow("janela", virt);  			// Abrindo janela para imagem
  imwrite("trocaregioes.png", virt);
  waitKey();
  return 0;
}
