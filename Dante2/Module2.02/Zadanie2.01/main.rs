use rand::random_range;

struct PointT {
    x: i32,
    y: i32,
}

fn show(p: & PointT) {
    println!("x: {} and y: {}", p.x, p.y);
}

fn distance(p1: & PointT, p2: & PointT) -> f32 {
    let distance: f32 = f32::sqrt((
        f32::powi(p2.x as f32 - p1.x as f32, 2)) +
        f32::powi(p2.x as f32 - p1.x as f32, 2));

    distance
}

fn set(p: &mut PointT, x: i32, y: i32) -> &mut PointT {
    p.x = x;
    p.y = y;

    p
}

fn read(p: &mut PointT) -> &mut PointT {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let x: i32 = input.trim().parse().expect("Incorrect parsing");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let y: i32 = input.trim().parse().expect("Incorrect parsing");

    p.x = x;
    p.y = y;

    p
}

fn main() {
    let num_x: i32 = random_range(0..10);
    let num_y: i32 = random_range(0..10);

    let mut p1 = PointT {
        x: 0,
        y: 0,
    };

    let mut p2 = PointT {
        x: 0,
        y: 0,
    };

    set(&mut p2, num_x, num_y);
    read(&mut p1);

    show(&mut p1);
    show(&mut p2);

    let result: f32 = distance(&p1, &p2);
    println!("Result is: {}", result);
}
