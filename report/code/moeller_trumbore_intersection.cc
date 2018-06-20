bool intersect(const Ray& ray, const Triangle& triangle, Vector3f& uvt) {
  const Vector3f edge_1 = triangle.vertex[1] - triangle.vertex[0];
  const Vector3f edge_2 = triangle.vertex[2] - triangle.vertex[0];
  const Vector3f rhs = ray.origin() - triangle.vertex[0];

  const Vector3f cross_1 = ray.direction().cross(edge_2);
  const Vector3f cross_2 = rhs.cross(edge_1);

  const float determinant = edge_1.dot(cross_1);
  const float inverse_determinant = 1.0f / determinant;

  uvt[0] = rhs.dot(cross_1);
  uvt[1] = ray.direction().dot(cross_2);
  uvt[2] = edge_2.dot(cross_2);
  uvt *= inverse_determinant;

  return (0.0f != determinant) && (uvt[0] >= 0.0f) && (uvt[1] >= 0.0f) &&
         (uvt[2] > 0.0f) && (uvt[0] + uvt[1] <= 1.0f);
}