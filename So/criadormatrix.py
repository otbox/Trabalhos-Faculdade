import numpy as np

# Definir o tamanho das matrizes
n_rows, n_cols = 50, 50

np.set_printoptions(threshold=np.inf, edgeitems=5)
# Criar a primeira matriz com números aleatórios inteiros entre 0 e 100
matrix1 = np.random.randint(0, 100, size=(n_rows, n_cols))

# Criar a segunda matriz com números aleatórios inteiros entre 0 e 100
matrix2 = np.random.randint(0, 100, size=(n_rows, n_cols))
# Exibir as matrizes
file = open("matrix.txt","w")
file.write("Matriz 1:")
file.write(str(matrix1).replace("[","").replace("]",""))
file.write("\nMatriz 2:")
file.write(str(matrix2).replace("[","").replace("]",""))
file.close()
