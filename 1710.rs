use std::cmp;
impl Solution {
    pub fn maximum_units(box_types: Vec<Vec<i32>>, truck_size: i32) -> i32 {
        let mut ret = 0;
        let mut box_selected = 0;
        box_types.sort_by(|a,b| b[1].cmp(&a[1]));

        for box_type in &box_types {
                let new_boxes = cmp::min(box_type[0], truck_size - box_selected);
                box_selected += new_boxes;
                ret += new_boxes * box_type[1];
        }

        ret
    }
}