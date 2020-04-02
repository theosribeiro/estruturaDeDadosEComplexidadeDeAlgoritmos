function insertSort(A) {

    for (var j = 1; j < array.length; j++) {
        var chave = A[j]
        var i = j - 1

        while (i >= 0 && A[i] > chave) {
            A[i + 1] = A[i]
            i = i - 1
        }
        A[i + 1] = chave
    }
    //console.log(A)
    alert("Ordenado: " + A)
}

//let array = [3, 5, 1, 9, 4, 20, 53, 22, 18]
//<script type="text/javascript">
var qtdeElementosArray = prompt("Digite a quantidade de elementos do Array: ")
var array = []

for (var i = 1; i <= qtdeElementosArray; i++) {
    var valorArray = prompt("Digite o " + i + "º valor do Array: ")
    array.push(valorArray)
}

alert("Sem Ordenação: " + array)

insertSort(array)