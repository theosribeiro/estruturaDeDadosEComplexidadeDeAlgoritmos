/*
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('What do you think of Node.js? ', (answer) => {
    // TODO: Log the answer in a database
    console.log(`Thank you for your valuable feedback: ${answer}`);

    rl.close();
});
*/
/*
var rl = readline.createInterface({
    input: fs.createReadStream('/path/file.txt'),
    output: process.stdout,
    terminal: false
})


rl.on('line', function (line) {
    console.log(line) // aqui podes fazer o que precisas com cada linha
})


fs.readFile('.\instancias-num\num.1000.1.in', 'utf-8', function (err, data) {
    var linhas = data.split(/\r?\n/);
    linhas.forEach(function (linha) {
        console.log(linha); // aqui podes fazer o que precisas com cada linha
    })
})
*/

function pegaArquivo(files) {
    var imgLoca = document.getElementById('imgLocal')
    var file = files[0];
    var img = document.createElement("img");
    img.file = file;

    imgLocal.appendChild(img)

    var reader = new FileReader();
    reader.onload = (function (aImg) { return function (e) { aImg.src = e.target.result; }; })(img);
    reader.readAsDataURL(file);
}


function selectiontSort(A) { //Ordenação por Seleção

    for (var i = 0; i < A.length; i++) {//loop invariante
        var chave = i //considerando o primeiro elemento do array como o menor valor

        //comparar o elemento selecionado com o posterior
        for (var j = i + 1; j < A.length; j++) {
            //se o elemento for menor, a chave vai ser esse elemento
            if (A[j] < A[chave]) chave = j;
        }
        //se o valor minimo for diferente da posição no array, troca os valores para o numero menor ficar antes do maior
        if (chave != i) [A[i], A[chave]] = [A[chave], A[i]]
    }
    //console.log(A)
    alert("Ordenado por SelectionSort: " + A)
}

//let array = [3, 5, 1, 9, 4, 20, 53, 22, 18]
//var qtdeElementosArray = prompt("Digite a quantidade de elementos do Array: ")
//var array = []

//for (var i = 1; i <= qtdeElementosArray; i++) {
    //var valorArray = prompt("Digite o " + i + "º valor do Array: ")
    //array.push(valorArray)
//}

//alert("Sem Ordenação: " + array)
//selectiontSort(array)