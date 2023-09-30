//Gustavo Fernandes Costa Tia:32161093

#include <stdio.h>
#include <string.h>

#define _ACEITA_ 1
#define _REJEITA_ 0

int estado = 0;

int scanner(const char *input) {
    int len = strlen(input);
    int i = 0;
    int pontoEncontrado = 0; // Variável para rastrear se um ponto foi encontrado
    
    
    if (len == 0) {
        return _REJEITA_; // A string está vazia, rejeita
    }

    q0:
      if (input[i] == '-' || input[i] == '+') {
        i++;
        goto q5; 
      }
      if (input[i] >= '1' && input[i] <= '9' ){
        i++;
        goto q1;
      }
      if (input[i] == ',' || input[i] == '.'){
        goto q2;
      }
        if (input[i] == '0'){
        i++;
        goto q3;
      }
      
      
        
    q1:
      if(i == len){
        estado = 1;
        return _ACEITA_;
      }
      if(input[i] >= '0' && input[i] <= '9' ){
        i++;
        goto q1;
      }
      if(input[i] == ','){
        i++;
        goto q7;
      }
      if(input[i] == '+' || input[i] == '-' || input[i] == '.' ){
        i++;
        goto q2; 
      }

    q2:
      estado = 4;
      return _REJEITA_;

    q3:
      if(i == len){
        estado = 3;
        return _ACEITA_;
      }
      if(input[i] == ','){
        i++;
        goto q7;
      }else{
        i++;
        goto q2;
      }
    q4:
      if(i == len){
        estado = 2;
        return _ACEITA_;
      }
      if(input[i] >= '0' && input[i] <= '9'){
        i++;
        goto q4;
      }
      else{
        i++;
        goto q2;
      }

    q5:
    if(i == len){
        estado = 5;
      return _REJEITA_;
    }
      if(input[i] >= '1' && input[i] <= '9'){
        i++;
        goto q1;
      }
      if(input[i] == '0'){
        i++;
        goto q6;
      }
      else{
        i++;
        goto q2;
      }
      
    q6:
    if(i == len){
        estado = 6;
        return _REJEITA_;
      }
      if(input[i] == ','){
        i++;
        goto q4;
      }
      else{
        i++;
        goto q2;
      }
    q7:
    if(i == len){
        estado = 7;
        return _REJEITA_;
      }
      if(input[i] >= '0' && input[i] <= '9'){
        i++;
        goto q4;
      }
      else{
        i++;
        goto q2;
      }
    
}

int main() {
    const char *input = "-21"; // Exemplo com sinal no início
    int resultado = scanner(input);

    if (resultado == _ACEITA_) {
      if(estado == 1){
        printf("A palavra '%s' é um numero inteiro aceito no estado final q1.\n", input);
      }
      if(estado == 2){
        printf("A palavra '%s' é um ponto flutuante aceito no estado final q4.\n", input);
      }
      if(estado ==3){
        printf("A palavra '%s' é um inteiro aceito no estado final q3.\n", input);
      }
    } else {
        if(estado == 4){
          printf("A string '%s' é um erro no estado q2.\n", input); 
      }
        if(estado ==5){
          printf("A string '%s' é um erro no estado q5.\n", input);
      }
        if(estado ==6){
          printf("A string '%s' é um erro no estado q6.\n", input);
          
      }
        if(estado ==7){
          printf("A string '%s' é um erro no estado q7.\n", input);
      }
         
    }

    return 0;
}
