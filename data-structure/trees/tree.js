class Node {
    value;
    children;
    parent;
    brother

    constructor(value) {
        this.value = value;
        this.children = [];
        this.parent = null;
    }
    setParentNode(node) {
        this.parent = node;
    }
    getParentNode() {
        return this.parent;
    }
    addChild(node) {
        node.setParentNode(this);
        this.children[this.children.length] = node;
    }
    getChildren() {
        return this.children;
    }
    removeChildren() {
        this.children = [];
    }
}
function printLevel(string, level) {
    let str = '';
    for (let a = 0; a < level; a++) {
        str += '\t';
    }
    console.log(`${str}${string}`);
}

function viewTree(node, level) {
    if (node.value) {
        let str = '';
        for (let a = 0; a < level; a++) {
            str += '\t';
        }
        printLevel(node.value, level)
        let child = node.getChildren();
        for (let i = 0; i < child.length; i++) {
            viewTree(child[i], level + 1);
        }
    }
}

let root = new Node('root');
let even = new Node('2');
even.addChild(new Node('4'));
even.addChild(new Node('6'));
even.addChild(new Node('8'));
even.addChild(new Node('10'));

let odd = new Node('1');
odd.addChild(new Node('3'));
odd.addChild(new Node('5'));
odd.addChild(new Node('7'));
odd.addChild(new Node('9'));

root.addChild(even);
root.addChild(odd);

viewTree(root, 0);