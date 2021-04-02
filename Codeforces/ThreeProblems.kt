fun main() {
    readLine()
    val arr = readLine()!!.split(" ").mapIndexed {index, it -> IndexedValue(index + 1, it.toInt()) }.sortedBy { it.value }.distinctBy { it.value }
    println(if(arr.size >= 3) "${arr[0].index} ${arr[1].index} ${arr[2].index}" else "-1 -1 -1")
}