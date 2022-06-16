nombre_archivo = input()
linea = input()
abecedario = "abcdefghijklmnopqrstuvwxyz "
numeros = [abecedario.index(letra) for letra in linea]
string = ""

for i in range(len(numeros)):
    string += str(numeros[i])
    if i != len(numeros) - 1:
        string += ','


with open(nombre_archivo, "w") as file:
    file.write(string)
