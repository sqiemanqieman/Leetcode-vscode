#pragma once
#include "bits/stdc++.h"
using namespace std;
#include "disjointset.h"

// 图抽象类
template <class TypeOfVer, class TypeOfEdge>
class graph {
public:
	virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w = 1) = 0;
	virtual void remove(int u, int v) = 0;  // u, v 是顶点编号
	virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0;
	int numOfVer() const { return Vers; }
	int numOfEdge() const { return Edges; }

protected:
	int Vers, Edges;
};


// 邻接矩阵 图
template<class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
	adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag) {
		int i, j;
		this->Vers = vSize;
		this->Edges = 0;
		this->noEdge = noEdgeFlag;

		// 存放节点的数组初始化
		ver = new TypeOfVer[vSize];
		for (i = 0; i < vSize; ++i) ver[i] = d[i];

		// 邻接矩阵初始化
		edge = new TypeOfEdge * [vSize];
		for (i = 0; i < vSize; ++i) {
			edge[i] = new TypeOfEdge[vSize];
			for (j = 0; j < vSize; ++j) edge[i][j] = noEdge;
			edge[i][i] = 0;
		}
	}
	void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w=1) {
		int u = find(x), v = find(y);
		edge[u][v] = w;
		++this->Edges;
	}

	void remove(int u, int v) {
		if (edge[u][v] == noEdge) return;
		edge[u][v] = noEdge;
		--this->Edges;
	}

	bool exist(TypeOfVer x, TypeOfVer y) const {
		int u = find(x), v = find(y);
		return edge[u][v] != noEdge;
	}

	~adjMatrixGraph() {
		delete[] ver;
		for (int i = 0; i < this->Vers; ++i) delete[] edge[i];
		delete[] edge;
	}

	int find(TypeOfVer v) const {
		for (int i = 0; i < this->Vers; ++i)
			if (ver[i] == v) return i;
		return -1;
	}

	// 所有顶点对最短路径 
	void floyd()const {
		TypeOfEdge** d = new TypeOfEdge * [this->Vers]; // 保存d矩阵每行的首地址
		int** prev = new int* [this->Vers]; // 保存prev矩阵每行首地址	
		int i, j, k;

		// 初始化
		for (i = 0; i < this->Vers; ++i) {
			d[i] = new TypeOfEdge[this->Vers];
			prev[i] = new int[this->Vers];
			for (j = 0; j < this->Vers; ++j) {
				d[i][j] = edge[i][j];
				prev[i][j] = (edge[i][j] != noEdge) ? i : -1;
			}
		}

		// 迭代过程
		for (k = 0; k < this->Vers; ++k)
			for (i = 0; i < this->Vers; ++i)
				for (j = 0; j < this->Vers; ++j)
					if (d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						prev[i][j] = prev[k][j];
					}

		// 输出过程
		cout << "所有顶点对最短路径是(Floyd):" << endl;
		cout << "最短路径长度：";
		for (i = 0; i < this->Vers; ++i) {
			cout << endl;
			for (j = 0; j < this->Vers; ++j) cout << d[i][j] << '\t';
		}

		cout << "\n最短路径(prev 数组):";
		for (i = 0; i < this->Vers; ++i) {
			cout << endl;
			for (j = 0; j < this->Vers; ++j) cout << prev[i][j] << '\t';
		}
	}

private:
	TypeOfEdge** edge;
	TypeOfVer* ver;
	TypeOfEdge noEdge;

};


// 邻接表 图
template<class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
	struct edgeNode {// 邻接表中存储边的结点类
		int end;	// 终点编号
		TypeOfEdge weight; // 边的权值
		edgeNode* next;
		edgeNode(int e, TypeOfEdge w, edgeNode* n = nullptr) : end(e), weight(w), next(n) {}
	};

	struct verNode { // 保存顶点的数据类型
		TypeOfVer ver; // 顶点值
		edgeNode* head; // 对应的单链表的头指针
		verNode(edgeNode* h = nullptr) : head(h) {}
	};

	adjListGraph(int vSize, const TypeOfVer d[]) {
		this->Vers = vSize; this->Edges = 0;

		verList = new verNode[vSize];
		for (int i = 0; i < this->Vers; ++i) verList[i].ver = d[i];
	}
	void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w=1) {
		int u = find(x), v = find(y);
		verList[u].head = new edgeNode(v, w, verList[u].head);
		++this->Edges;
	}

	void remove(int u, int v) {
		edgeNode* p = verList[u].head, * q;
		if (p == nullptr) return; // 节点u没有相邻的边
		if (p->end == v) {
			verList[u].head = p->next;
			delete p;
			--this->Edges;
			return;
		}
		while (p->next && p->next->end != v) p = p->next; // 查找被删除的边
		if (p->next) { // 删除
			q = p->next;
			p->next = q->next;
			delete q;
			--this->Edges;
		}
		return;
	}

	bool exist(TypeOfVer x, TypeOfVer y) const {
		int u = find(x), v = find(y);
		edgeNode* p = verList[u].head;

		while (p && p->end != v) p = p->next;
		if (p == nullptr) return false;
		return true;
	}

	~adjListGraph() {
		int i = 0;
		edgeNode* p;
		for (i = 0; i < this->Vers; ++i) {
			while ((p = verList[i].head) != nullptr) {
				verList[i].head = p->next;
				delete p;
			}
		}
		delete[] verList;
	}

	// DFS
	void dfs() const {
		bool* visited = new bool[this->Vers]; // 记录每个节点是否已被访问
		for (int i = 0; i < this->Vers; ++i) visited[i] = false;
		cout << "深度优先遍历序列" << endl;
		for (int i = 0; i < this->Vers; ++i) {
			if (visited[i] == true) continue;
			dfs(i, visited);
			cout << endl;
		}
	}

	void dfs(int start, bool visited[]) const {
		edgeNode* p = verList[start].head;

		cout << verList[start].ver << '\t'; // 访问节点
		visited[start] = true;

		while (p) {
			if (visited[p->end] == false) dfs(p->end, visited);
			p = p->next;
		}
	}

	// BFS
	void bfs() const {
		bool* visited = new bool[this->Vers];
		int currentNode;
		queue<int> q;
		edgeNode* p;

		for (int i = 0; i < this->Vers; ++i) visited[i] = false;

		cout << "广度优先遍历序列：" << endl;

		for (int i = 0; i < this->Vers; ++i) {
			if (visited[i] == true) continue;
			q.push(i);
			while (!q.empty()) {
				currentNode = q.front();
				q.pop();
				if (visited[currentNode] == true) continue;
				cout << verList[currentNode].ver << '\t';
				visited[currentNode] = true;
				p = verList[currentNode].head;
				while (p) {
					if (visited[p->end] == false) q.push(p->end);
					p = p->next;
				}
			}
			cout << endl;
		}
	}

	// 欧拉回路
	struct EulerNode {
		int NodeNum;
		EulerNode* next;
		EulerNode(int ver) : NodeNum(ver), next(nullptr) {}
	};

	verNode* clone() const {
		verNode* tmp = new verNode[this->Vers];
		edgeNode* p;
		for (int i = 0; i < this->Vers; ++i) {
			tmp[i].ver = verList[i].ver;
			p = verList[i].head;
			while (p) {
				tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
				p = p->next;
			}
		}
		return tmp;
	}

	void EulerCircuit(int start, EulerNode*& beg, EulerNode*& end) {
		int nextNode;
		beg = end = new EulerNode(start);
		while (verList[start].head) {
			nextNode = verList[start].head->end;
			remove(start, nextNode);
			remove(nextNode, start);
			start = nextNode;
			end->next = new EulerNode(start);
			end = end->next;
		}
	}

	void EulerCircuit(TypeOfVer start) {
		EulerNode* beg, * end, * p, * q, * tb, * te;
		int numOfDegree;
		edgeNode* r;
		verNode* tmp;
		int n_edges;

		// 检查是否存在欧拉回路
		if (this->Edges == 0)  return; // 不存在
		for (int i = 0; i < this->Vers; ++i) {
			numOfDegree = 0;
			r = verList[i].head;
			while (r) {
				++numOfDegree;
				r = r->next;
			}
			if (numOfDegree % 2) return; // 不存在
		}

		// 寻找起始节点编号
		int i = find(start);
		tmp = clone();
		n_edges = this->numOfEdge();

		// 寻找从i出发的路径，路径的起点和终点地址分别是beg和end
		EulerCircuit(i, beg, end);
		while (true) {
			p = beg;
			while (p->next) // 检查p的后继节点是否有边尚未被访问
				if (verList[p->next->NodeNum].head) break;
				else p = p->next;
			if (p->next == nullptr) break; // 所有的边都已被访问
			q = p->next; // 尚有未被访问的边
			EulerCircuit(q->NodeNum, tb, te); // 从此节点开始找一段回路
			te->next = q->next;
			p->next = tb;
			delete q;
		}

		// 恢复原图
		delete[] verList;
		verList = tmp;
		this->Edges = n_edges;

		// 显示得到的欧拉回路
		cout << "欧拉回路是：" << endl;
		while (beg) {
			cout << verList[beg->NodeNum].ver << '\t';
			p = beg;
			beg = beg->next;
			delete p;
		}
		cout << endl;
	}

	//拓扑排序
	void topSort()	const {
		queue<int> q;
		edgeNode* p;
		int current;
		int* inDegree = new int[this->Vers];

		for (int i = 0; i < this->Vers; ++i){
			inDegree[i] = 0;
			for (p = verList[i].head; p; p = p->next) ++inDegree[p->end];
		}
		
		for (int i = 0; i < this->Vers; ++i)  if (inDegree[i] == 0) q.push(i);

		cout << "拓扑排序是：" << endl;
		while (!q.empty()) {
			current = q.front();
			q.pop();
			cout << verList[current].ver << "\t";
			for (p = verList[current].head; p; p = p->next) {
				if (--inDegree[p->end] == 0)
					q.push(p->end);
			}
		}
		cout << endl;
	}

	// 关键路径
	void criticalPath() const {
		TypeOfEdge* ee = new TypeOfEdge[this->Vers], * le = new TypeOfEdge[this->Vers];
		int* top = new int[this->Vers], * inDegree = new int[this->Vers];
		queue<int> q;
		int i;
		edgeNode* p;

		//找出拓扑序列， 放入数组top
		for (int i = 0; i < this->Vers; ++i) {
			inDegree[i] = 0;
			for (p = verList[i].head; p; p = p->next) ++inDegree[p->end];
		}
		for (int i = 0; i < this->Vers; ++i)  if (inDegree[i] == 0) q.push(i);
		i = 0;
		while (!q.empty()) {
			top[i] = q.front();
			q.pop();
			for (p = verList[top[i]].head; p; p = p->next)
				if (--inDegree[p->end] == 0) q.push(p->end);
			++i;
		}

		// 找出最早发生时间
		for (int i = 0; i < this->Vers; ++i) ee[i] = 0;
		for (int i = 0; i < this->Vers; ++i) { //找出最早发生时间存于数组ee
			for (p = verList[top[i]].head; p; p = p->next)
				if (ee[p->end] < ee[top[i]] + p->weight)
					ee[p->end] = ee[top[i]] + p->weight;
		}

		// 找出最晚发生时间
		for (int i = 0; i < this->Vers; ++i) le[i] = ee[top[this->Vers - 1]];
		for (int i = this->Vers - 1; i >= 0; --i) { //找出最晚发生时间存于数组le
			for (p = verList[top[i]].head; p; p = p->next)
				if (le[p->end] - p->weight < le[top[i]])
					le[top[i]] = le[p->end] - p->weight;
		}

		cout << "关键路径是：" << endl;
		for (int i = 0; i < this->Vers; ++i) // 找出关键路径
			if (le[top[i]] == ee[top[i]])
				cout << "(" << verList[top[i]].ver << ", " << ee[top[i]] << ")";
		cout << endl;
	}

	// 最小生成树 Kruskal 从边的角度出发
	struct edge {
		int beg, end;
		TypeOfEdge w;
		bool operator<(const edge& rp) const { return w > rp.w; };
	};

	void kruskal() const {
		int edgesAccepted = 0, u, v;
		edgeNode* p;
		edge e;
		disJointSet ds(this->Vers);
		priority_queue<edge> pq;

		// 生成优先级队列
		for (int i = 0; i < this->Vers; ++i) {
			for (p = verList[i].head; p; p = p->next)
				if (i < p->end) {
					e.beg = i;
					e.end = p->end;
					e.w = p->weight;
					pq.push(e);
				}
		}

		// 开始归并
		cout << "最小生成树是:" << endl;
		while (edgesAccepted < this->Vers - 1) {
			e = pq.top(); // 取出最小边
			pq.pop();
			u = ds.find(e.beg);
			v = ds.find(e.end);
			if (u != v) { // 加入(u,v)不会形成回路
				edgesAccepted++;
				ds.merge(u, v);
				cout << "(" << verList[e.beg].ver << "," << verList[e.end].ver << ")\t";
			}
		}
		cout << endl;
	}

	// 最小生成树 Prim 从顶点的角度出发
	void prim(TypeOfEdge noEdge) const {
		bool* flag = new bool[this->Vers];
		TypeOfEdge* lowCost = new TypeOfEdge[this->Vers];
		int* startNode = new int[this->Vers];
		
		edgeNode* p;
		TypeOfEdge min;
		int start, i, j;

		for (i = 0; i < this->Vers; ++i){//初始化，所有节点都不在树中
			flag[i] = false;
			lowCost[i] = noEdge;
		}

		cout << "最小生成树是:" << endl;
		start = 0; // 将0作为第一个加入生成树的节点
		for (i = 0; i < this->Vers - 1; ++i) {
			for (p = verList[start].head; p; p = p->next) // 检查start的边
				if (!flag[p->end] && lowCost[p->end] > p->weight){ // 更新距离信息
					lowCost[p->end] = p->weight;
					startNode[p->end] = start;
				}
			flag[start] = true;  // 将start标记为已在U中
			min = noEdge;
			for (j = 0; j < this->Vers; ++j) // 寻找U到V-U的权值最小的边
				if (lowCost[j] < min) { min = lowCost[j]; start = j; }
			cout << "(" << verList[startNode[start]].ver << "," << verList[start].ver << ")\t";
			lowCost[start] = noEdge;
		}
		cout << endl;
		delete[] flag;
		delete[] startNode;
		delete[] lowCost;
	}

	// 单源最短路径 unweighted
	void printPath(int start, int end, int prev[])const {
		if (start == end) {
			cout << verList[start].ver;
			return;
		}
		printPath(start, prev[end], prev);
		cout << "-" << verList[end].ver;
	}

	void unweightedShortDistance(TypeOfVer start, TypeOfEdge noEdge)const {
		queue<int> q;
		TypeOfEdge* distance = new TypeOfEdge[this->Vers];
		int* prev = new int[this->Vers];
		int u, sNo;
		edgeNode* p;
		for (int i = 0; i < this->Vers; ++i) distance[i] = noEdge; // 初始化
		
		sNo = find(start);//起始节点编号
		// 寻找最短路径
		distance[sNo] = 0;
		prev[sNo] = sNo;
		q.push(sNo);

		while (!q.empty()) {
			u = q.front();
			q.pop();
			for (p = verList[u].head; p; p = p->next)
				if (distance[p->end] == noEdge) {
					distance[p->end] = distance[u] + 1;
					prev[p->end] = u;
					q.push(p->end);
				}
		}

		// 输出最短路径
		cout << "Unweighted 单源最短路径是：" << endl;
		for (int i = 0; i < this->Vers; ++i) {
			cout << "从" << start << "到" << verList[i].ver << "的路径为:" << endl;
			printPath(sNo, i, prev);
			cout << endl;
		}
	}

	// 单源最短路径 Dijkstra
	void dijkstra(TypeOfVer start, TypeOfEdge noEdge) const {
		TypeOfEdge* distance = new TypeOfEdge[this->Vers];
		int* prev = new int[this->Vers];
		bool* known = new bool[this->Vers];

		int u, sNo, i, j;
		edgeNode* p;
		TypeOfEdge min;

		for (i = 0; i < this->Vers; ++i) { // 初始化
			known[i] = false;
			distance[i] = noEdge;
		}
		
		sNo = find(start);
		distance[sNo] = 0;
		prev[sNo] = sNo;

		for (i = 1; i < this->Vers; ++i) {
			min = noEdge;
			for (j = 0; j < this->Vers; ++j) // 寻找具有最短距离的节点
				if (!known[j] && distance[j] < min) {
					min = distance[j];
					u = j;
				}
			known[u] = true; // 将u放入S
			for (p = verList[u].head; p; p = p->next) // 更新u的邻接点距离
				if (!known[p->end] && distance[p->end] > min + p->weight) {
					distance[p->end] = min + p->weight;
					prev[p->end] = u;
				}
		}

		cout << "Weighted 单源最短路径是(Dijkstra)：" << endl;
		for (i = 0; i < this->Vers; ++i) { // 输出所有路径信息
			cout << "从" << start << "到" << verList[i].ver << "的路径为:" << endl;
			printPath(sNo, i, prev);
			cout << "\t 长度为：" << distance[i] << endl;
		}
	}

	int find(TypeOfVer v) const {
		for (int i = 0; i < this->Vers; ++i) {
			if (verList[i].ver == v) return i;
		}
		return -1;
	}

private:
	verNode* verList;
};