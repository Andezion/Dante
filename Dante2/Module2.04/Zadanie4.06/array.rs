#[derive(Default)]
pub struct ArrayT {
    pub array: Vec<i32>,
    pub size: usize,
    pub capacity: usize,
}

pub fn array_create(a: &mut ArrayT, size: usize) {
    a.array = vec![0; size];
    a.size = 0;
    a.capacity = size;
}

pub fn array_push_back(a: &mut ArrayT, value: i32) -> i32 {
    if a.size > a.capacity || a.capacity <= 0 {
        return 1;
    }

    if a.size == a.capacity {
        return 2;
    }

    a.array[a.size] = value;
    a.size += 1;

    0
}

pub fn array_display(a: & ArrayT) {
    if a.size > a.capacity || a.capacity <= 0 {
        return;
    }
    for i in 0..a.size {
        print!("{} ", a.array[i]);
    }
}
