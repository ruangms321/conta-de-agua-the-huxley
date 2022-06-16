#include <stdio.h>
/*Uma empresa de importa��o de produtos eletr�nicos em parceria com o CIn deseja fazer um programa que calcule o valor final do produto e discrimine na nota fiscal quanto o cliente pagou em impostos(Imposto de importa��o e ICMS), frete e total a pagar. Segue algumas informa��es que voc� precisar� saber para resolver essa quest�o:


    A taxa de importa��o para eletr�nicos � de 60%;
    O calculo do ICMS � dado pela formula: (Valor Final do produto x Aliquota)
    O valor final do produto � dado pela soma do (Valor do Produto + Frete + Impostos de Importa��o) / (1 - Aliquota)
    A empresa tema cultura de n�o adicionar o frete no calculo, para valores de US$ 2,500 em diante. Informe isso ao fim da nota.

    Sua entrada deve conter

    -Cota��o do Dolar
    -Aliquota(%) do ICMS
    -Valor do produto
    -Valor do frete	
*/

void isencao(double array[]){
    if(array[6] < 2500){
       
        //valor final
        //7 = (6 + 10 + 4)/ "1"- 1
            /*
            7 valor final
            6 valor do prodto em R$
            10 frete em rs
            4 impostos
            1 aliquota icms
            */

            array[7] = (array[6] + array[10] + array[4]) / (1 - (array[1] / 100));
       //8 icms calculado 
            array[8] = array[7] * (array[1] / 100);
    }


    else{
       
        //7 = (6 + 4)/ "1"- 1
            /*
            7 valor final
            6 valor do prodto em R$
            4 impostos
            1 aliquota icms
            */
        array[7] = (array[6] + array[4]) / (1 - (array[1] / 100));
       //8 icms calculado 
            array[8] = array[7] * (array[1] / 100);
    }
}
void taxacao(double array_geral[]){//60%
    array_geral[4] = (array_geral[6] * 60) / 100;
}
void conversao_em_dolaresP(double convertido[]){//produto para reais

    /*
    6 produto convertido em r$
    2 produto do produto em u$
    0 cotacao do dolar
    */

    convertido[6] = convertido[2] * convertido[0];
}
void conversao_em_dolaresF(double convertido[]){//fret para reais

    /*
    10 fret convertido em r$
    3 fret do produto em u$
    0 valor da cotacao do dolar
    */

    convertido[10] = convertido[3] * convertido[0];
}

void preencher_array(double entradas[], int i){//preencher de 0 a 3 as entradas

    /* preenche array com 
    -Cota��o do Dolar
    -Aliquota(%) do ICMS
    -Valor do produto
    -Valor do frete	
    */

    if(i < 4){
        scanf("%lf", &entradas[i]);
        i++;
        preencher_array(entradas, i);
        }

    else{
        return;
        }

}



int main(){
    double array_geral[11];
    /*
    ><
    0 cotacao do dolar
    1 aliquota iCMS
    2 valor do produto em u$
    3 frete
    ><
    4 imposto de 60%             xxx
    5 produto + fret             xxx
    6 produto convertido em r$   xxx
    7 valor final                xxx
    8 icms calculado             xxx  
    9 60% + icms                 xxx
    10 frete em reais            xxx
    ><
    total = 9 + 5
    */

    preencher_array(array_geral, 0);
    conversao_em_dolaresF(array_geral);
    conversao_em_dolaresP(array_geral);
    array_geral[5] = array_geral[6] + array_geral[10];
    taxacao(array_geral);
    isencao(array_geral); 
    array_geral[9] = array_geral[4] + array_geral[8]; printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n", array_geral[0], array_geral[6], array_geral[10], array_geral[5], array_geral[4], array_geral[8], array_geral[9], array_geral[9] + array_geral[5]);
  if(array_geral[6] < 2500){
        printf("Impostos calculados com o frete");
  }
  else{
        printf("Impostos calculados sem o frete");
  }}
