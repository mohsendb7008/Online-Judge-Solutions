// Parking

fun convertToIntArray(n: Int, l: List<String>): IntArray{
    val stores = IntArray(n)
    for(i in 0 until n)
        stores[i] = l[i].toInt()
    return stores
}

fun solve(n: Int, stores: IntArray){
    stores.sort()
    // print("stores = ")
    // println("[${stores.joinToString(separator = ", ")}]")
    var ans = 0
    for(i in 1 until n)
        ans += stores[i] - stores[i-1]
    println(2 * ans)
}

fun main(){
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        val stores = convertToIntArray(n, readLine()!!.split(" "))
        solve(n, stores)
    }
}