#ifndef L9110_h
#define L9110_h

class L9110 {
  public:
    L9110(int aia, int aib, int bia, int bib);
    void adelante(int l, int r, int t);
    void atras(int l, int r, int t);
    void girar(int l, int r, int t);
    void frenar(int t);
    void control_fino(int l, int r, int t);
  private:
    int _aia;
    int _aib;
    int _bia;
    int _bib;
}; 

#endif