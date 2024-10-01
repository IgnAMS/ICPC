# Huawei Challenge Post ICPC WF 2023



## IEEE limites de valores por tipo

|      | Signo | Mantisa  | Exponente    | Max Number         | Min Number   |
|------|-------|----------|--------------|--------------------|--------------|
|FP16  |   1   | 10       |  5           | 2^16 = 6.5504E4    | 6.10352E-5   |
|FP32  |   1   | 23       |  8           | 2^128 = 3.402E38   | 1.17549E-38  |
|FP64  |   1   | 53       |  11          | 2^1024 = 1E300     | 1E-300       |


## Scoring
Viendo el scoring nos damos cuentas de algunas cosas:
1. A corresponde en cierta manera al error porcentual obtenido elevado a 0.05. El 0.05 lo que hace es aumentar el error ya que al ser porcentual se obtiene un número menor a 1 y lo que hace el 0.05 es amplificarlo a su raiz. Notamos que queremos minimizar este número ya que divide el resultado final del score. También, por los ejemplos provistos nos damos cuenta de que debemos hacer una diferencia significante del error para poder cambiar su valor.

2. W es una penalización que se obtiene por el tipo de variable a usar. Notamos que se pondera según la cantidad de sumas que se tengan en el formato. Notamos que si o si hay N - 1 sumas en total y queremos minimizar la cantidad de está penalización.

3. P es una penalización por lectura del bloque. La lectura la dividimos en bloques de 16 entradas. Tenemos que la penalización de un bloque es la sumatoria acumulada de los valores. En el peor de los casos se tiene 15^2 * (N / 16) ~ 16 * N.

4.  C es la suma de W y P divido en N - 1. Notamos que este valor es mayor o igua a 1 ya que en el mejor de los casos W = N - 1.

5. D es 10. / raiz(C + 0.5). Notamos que el 10 es innecesario para el problema y que como C es 

6. Scre es D / A, por lo que queremos maximizar D y minimizar A. Posiblemente lo mejor sea tener una muy buena precisión ya que tiene un alto grado de relevancia en el problema y queramos

Nota: La penalización de P tiende a ser mayor a la penalización de W ya que el peor de los casos de P es 16 * N y el peor de los casos de W es 4 * N.


## Opciones
En bloques de 16 veremos cuales son de tipo similares para sumarlos. Para esto haremos algunas clasificaciones de tipos.

### Idea 1:
|      | Max Number         |  Max number / 16   | Min Number   |  Min number / 16 |
|------|--------------------|--------------------|--------------|------------------|
|FP16  | 2^16 = 6.5504E4    |     4.094  E3      | 6.10352E-5   |                  |
|FP32  | 2^128 = 3.408E38   |     2.1267 E37     | 1.17549E-38  |                  |
|FP64  | 2^1024 = 1E300     |     6.25   E298    | 1E-300       |                  |

