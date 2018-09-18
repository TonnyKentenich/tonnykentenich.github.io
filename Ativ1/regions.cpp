#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image;	// Classe Mat a(nL, nC, CV_8U);
  Vec3b val;	// Vetores
  int x1=0, x2=0, y1=0, y2=0;

  image= imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);	// Grayscale -> matriz com tons de cinza / "unsigned char" -> "uchar" 255 bits
  if(!image.data)
    cout << "nao abriu o arquivo" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);	// Nomeando e identificando janelas

    cout << "escreva as cordenadas x1 y1 no formato: ( valor [enter] valor )" << endl;
    cin >> x1 >> y1;
    cout << endl;
    cout << "escreva as cordenadas x2 y2 no formato: ( valor [enter] valor )" << endl;
    cin >> x2 >> y2;
    cout << endl;

  
  for(int i=x1;i<x2;i++){
    for(int j=y1;j<y2;j++){
      image.at<uchar>(i,j)=255-image.at<uchar>(i,j);			// Acessando elementos unsigned.. gravando numero 0
    }
  }
  
  imshow("janela", image);  			// Abrindo janela para imagem
  imwrite("regions.png", image);
  waitKey();
  return 0;
}
