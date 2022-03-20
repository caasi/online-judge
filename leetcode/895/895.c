typedef struct Q {
    int val;
    int sp;
    int time[20000];
    struct Q* left;
    struct Q* right;
} Q;

Q* qCreate(int val, int time) {
    Q* q = malloc(sizeof(Q));
    q->val = val;
    q->sp = 0;
    q->time[q->sp++] = time;
    return q;
}

void qTouch(Q* q, int time) {
    q->time[q->sp++] = time;
}

int qDrain(Q* q) {
    if (!q->sp) return q->val;
    q->time[--q->sp];
    return q->val;
}

Q* qRotateLeft(Q* q) {
    Q* right = q->right;
    if (!right) return q;
    q->right = right->left;
    right->left = q;
    return right;
}

Q* qRotateRight(Q* q) {
    Q* left = q->left;
    if (!left) return q;
    q->left = left->right;
    left->right = q;
    return left;
}

bool qIsGE(Q* q, Q* node) {
    int qLen = q ? q->sp : 0;
    int nodeLen = node ? node->sp : 0;
    int qHead = qLen > 0
        ? q->time[qLen - 1]
        : -1;
    int nodeHead = nodeLen > 0
        ? node->time[nodeLen - 1]
        : -1;
    if (qLen > nodeLen) return true;
    if (qLen == nodeLen && qHead > nodeHead) return true;
    return false;
}

Q* qBalance(Q* q) {
    Q* curr = q;
    if (!curr) return NULL;
    if (qIsGE(curr, curr->left) && qIsGE(curr, curr->right)) {
        return curr;
    }
    if (qIsGE(curr->left, curr->right)) {
        curr = qRotateRight(curr);
        curr->right = qBalance(curr->right);
        return curr;
    } else {
        curr = qRotateLeft(curr);
        curr->left = qBalance(curr->left);
        return curr;
    }
}

Q* qPush(Q* q, int val, int time) {
    if (!q) {
        return qCreate(val, time);
    }
    if (q->val == val) {
        qTouch(q, time);
        return qBalance(q);
    }
    if (q->val > val) {
        q->left = qPush(q->left, val, time);
    } else {
        q->right = qPush(q->right, val, time);
    }
    return qBalance(q);
}

void qFree(Q* q) {
    if (q) {
        if (q->left) {
            qFree(q->left);
            q->left = NULL;
        }
        if (q->right) {
            qFree(q->right);
            q->right = NULL;
        }
        free(q);
    }
}

typedef struct {
    Q* q;
    int time;
} FreqStack;


FreqStack* freqStackCreate() {
    FreqStack* s = malloc(sizeof(FreqStack));
    s->q = NULL;
    s->time = 0;
    return s;
}

void freqStackPush(FreqStack* obj, int val) {
    obj->q = qPush(obj->q, val, obj->time++);
}

int freqStackPop(FreqStack* obj) {
    int val = qDrain(obj->q);
    obj->q = qBalance(obj->q);
    return val;
}

void freqStackFree(FreqStack* obj) {
    if (obj) {
        qFree(obj->q);
        obj->q = NULL;
        free(obj);
    }
}