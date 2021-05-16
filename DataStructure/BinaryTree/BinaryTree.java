package BinaryTree;

public class BinaryTree<T> {
	
	private Node<T> root;
	
	public BinaryTree(T data) {
		this.root = new Node<T>(data);
	}

	public Node<T> getRoot() {
		return root;
	}
	
	public void addLeft(Node<T> parent, T data) {
		parent.setLeft(new Node<T>(data));
	}
	
	public void addRight(Node<T> parent, T data) {
		parent.setRight(new Node<T>(data));
	}

	public void removeLeft(Node<T> node) {
		node.setLeft(null);
	}
	
	public void removeRight(Node<T> node) {
		node.setRight(null);
	}
	
	private void traversePreorder(Node<T> node) {
		if(node != null) {
			System.out.print(node.getData() +" ");
			
			traversePreorder(node.getLeft());
			traversePreorder(node.getRight());
		}
	}
	
	public void traversePreorder() {
		traversePreorder(root);
		System.out.println("");
	}
	
	private void traverseInorder(Node<T> node) {
		if(node != null) {			
			traverseInorder(node.getLeft());
			System.out.print(node.getData() +" ");
			traverseInorder(node.getRight());
		}
	}
	
	public void traverseInorder() {
		traverseInorder(root);
		System.out.println("");
	}
	
	private void traversePostorder(Node<T> node) {
		if(node != null) {			
			traversePostorder(node.getLeft());
			traversePostorder(node.getRight());
			
			System.out.print(node.getData() +" ");
		}
	}
	
	public void traversePostorder() {
		traversePostorder(root);
		System.out.println("");
	}
}
