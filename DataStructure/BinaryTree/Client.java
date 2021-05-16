package BinaryTree;

public class Client {

	public static void main(String[] args) {
		BinaryTree<Integer> tree = new BinaryTree<>(0);
		
		// make tree
		tree.addLeft(tree.getRoot(), 1);
		tree.addRight(tree.getRoot(), 2);
		
		tree.addLeft(tree.getRoot().getLeft(), 3);
		tree.addRight(tree.getRoot().getLeft(), 4);
		
		tree.addLeft(tree.getRoot().getRight(), 5);
		tree.addRight(tree.getRoot().getRight(), 6);
		
		// traverse
		tree.traversePreorder();
		tree.traverseInorder();
		tree.traversePostorder();
	}
	

}
