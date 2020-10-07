data class Request(val size: Int, val price: Int, val index: Int)
data class Table(val size: Int, val index: Int)

val requests = ArrayList<Request>()
val tables = ArrayList<Table>()

val table = Array(1003){IntArray(1003)}
val trace = Array(1003){BooleanArray(1003)}

val matches = ArrayList<Pair<Int, Int>>()

fun main() {
    val n = readLine()!!.toInt()
    for (i in 1..n){
        val(c, p) = readLine()!!.split(" ").map { it.toInt() }
        requests.add(Request(c, p, i))
    }
    val k = readLine()!!.toInt()
    val line = readLine()!!.split(" ")
    for(i in 1..k){
        val s = line[i-1].toInt()
        tables.add(Table(s, i))
    }
    requests.sortBy { it.size }
    tables.sortBy { it.size }
    for(i in 0..n)
        for(j in 0..k){
            if(i == 0 || j == 0)
                table[i][j] = 0
            else{
                table[i][j] = table[i-1][j]
                trace[i][j] = false
                if(requests[i-1].size <= tables[j-1].size && table[i-1][j-1] + requests[i-1].price > table[i][j]){
                    table[i][j] = table[i-1][j-1] + requests[i-1].price
                    trace[i][j] = true
                }
            }
        }
    var(i, j) = n to k
    while(i != 0 && j != 0){
        if(trace[i][j]){
            matches.add(requests[i-1].index to tables[j-1].index)
            j--
        }
        i--
    }
    println("${matches.size} ${table[n][k]}")
    matches.forEach {
        println("${it.first} ${it.second}")
    }
}
