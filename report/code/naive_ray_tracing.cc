Intersection trace(const Ray& ray, const Scene& scene) {
  // construct non-valid default intersection
  Intersection intersection;

  // compute intersections for every triangle
  for (const auto& triangle : scene) {
    Vector3f uvt;
    if (!intersect(ray, triangle, uvt)) continue;

    // use closer intersection
    if (uvt[2] < intersection.t()) {
      intersection.uvt() = uvt;
      intersection.triangle() = &triangle;
    }
  }

  return intersection;
}