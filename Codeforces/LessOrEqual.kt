fun main() {
    val(n, k) = readLine()!!.split(" ").map { it.toInt() }
    val arr = readLine()!!.split(" ").map { it.toInt() }.toIntArray().sorted()
    if(k == 0){
        println(if(arr[0] == 1) -1 else 1)
        return
    }
    println(if(k < n && arr[k] == arr[k-1]) -1 else arr[k-1])
}