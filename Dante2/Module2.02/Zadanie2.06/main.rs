#[derive(Default)]
struct PointT {
    x: i32,
    y: i32,
}
#[derive(Default)]
struct SegmentT {
    start: PointT,
    end: PointT,
}
fn main() {
    let mut p: SegmentT = Default::default();
    read_segment(&mut p);
    show_segment(&p);

    let result: f32 = length(&p);
    print!("{}", result);
}

fn read_segment(p: &mut SegmentT) -> & SegmentT {
    let mut input: String = String::new();

    println!("Enter: x1");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect");
    p.start.x = input.trim().parse().expect("Incorrect");

    println!("Enter: y1");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect");
    p.start.y = input.trim().parse().expect("Incorrect");

    println!("Enter: x2");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect");
    p.end.x = input.trim().parse().expect("Incorrect");

    println!("Enter: y2");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Incorrect");
    p.end.y = input.trim().parse().expect("Incorrect");

    p
}

fn show_segment(p: & SegmentT) {
    println!("{}; {}", p.start.x, p.start.y);
    println!("{}; {}", p.end.x, p.end.y);
}

fn length(p: & SegmentT) -> f32 {
    let distance: f32 = f32::sqrt((f32::powi((p.end.x - p.start.x) as f32, 2)) +
        (f32::powi((p.end.y - p.start.y) as f32, 2)));
    distance
}
