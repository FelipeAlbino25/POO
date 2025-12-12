#ifndef VETOR_H
#define VETOR_H

template <typename T>

class vetor //vetores de inteiros
{

public:
   vetor(int=10); 	//construtor. O par�metro int define o tamanho do vetor
   ~vetor(); 		//destrutor
   int get_tamanho() const;	//retorna o tamanho do vetor
   bool SetValor(int pos, T val);	//altera o valor da posi��o "pos" para "val". 
   									//retorna "true" em caso de sucesso e falso em caso de insucesso
   bool GetValor(int pos, T& val) const; 	// em caso de sucesso, retorna "true" e o valor da posi��o "pos" em "val" (passada por refer�ncia). 
   void imprime() const; //m�todo auxiliar para impress�o do vetor na tela (console)

private:
   int tam;  			//tamanho do vetor
   T *ptrvalores;		//ponteiro para a primeira posi��o do vetor

};


template <typename T>

vetor<T>::vetor(int x)
{
   if (x > 0) 
     tam = x;
   else
     tam = 10;                 

   ptrvalores = new int[tam];

   for (int i=0;i<tam;i++)
      SetValor(i,0);
}
template <typename T>

vetor<T>::~vetor()
{
   delete [] ptrvalores;
}
template <typename T>

int vetor<T>::get_tamanho() const{
    return tam;   
}

template <typename T>
bool vetor<T>::SetValor(int pos, T val)
{
   if (pos >=0 && pos < tam)
      {
      ptrvalores[pos] = val; 
      return true;
      }
   else 
      return false;   
}
template <typename T>

bool vetor<T>::GetValor(int pos, T& val) const
{
    if (pos >= 0 && pos < tam)
      {
         val =ptrvalores[pos];
         return true;
      }
    else
        return false;
}

template <typename T>

void vetor<T>::imprime() const
{
     int valor;
     for (int i=0;i<get_tamanho();i++){
        GetValor(i, valor);
        std::cout << valor << " ";
        }
     std::cout << std::endl;
}


#endif /*VETOR_H*/ 


