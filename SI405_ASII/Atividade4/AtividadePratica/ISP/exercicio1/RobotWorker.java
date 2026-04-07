class RobotWorker implements Worker {

    public void work() {
        System.out.println("Robot working...");
    }

    public void eat() {
        throw new UnsupportedOperationException("Robot does not eat");
    }
}
