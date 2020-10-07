val order = mapOf('k' to 0, 'o' to 1, 't' to 2, 'l' to 3, 'i' to 4, 'n' to 5)
val kotlin = mapOf('k' to 'o', 'o' to 't', 't' to 'l', 'l' to 'i', 'i' to 'n', 'n' to 'k')
val graph = Array(6){ArrayList<Pair<Int, Int>>()}

var ptr = 0
val euler = IntArray(100003)

fun dfs(u: Int){
    val adj = graph[u]
    while(adj.isNotEmpty()) {
        val edge = adj.removeAt(adj.indices.last)
        dfs(edge.first)
        euler[ptr++] = edge.second + 1
    }
}

fun main(){
    val n  = readLine()!!.toInt()
    for(i in 0 until n) {
        val piece = readLine()!!
        graph[order.getOrDefault(piece[0], 6)].add(order[kotlin[piece.last()]]!! to i)
    }
    dfs(0)
    for(i in n-1 downTo 0)
        print("${euler[i]} ")
}