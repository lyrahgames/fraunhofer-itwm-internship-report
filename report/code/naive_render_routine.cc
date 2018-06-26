void render(const Scene& scene, const Camera& camera,
            Pixel_buffer& pixel_buffer) {
  // make sure pixel buffer has allocated memory needed
  pixel_buffer.resize(camera.screen_width() * camera.screen_height());

  // trace a ray for every pixel
  for (auto i = 0; i < camera.screen_height(); ++i) {
    for (auto j = ; j < camera.screen_width(); ++j) {
      const Ray ray = primary_ray(camera, j, i);
      const auto intersection = trace(ray, scene);
      if (intersection) {
        // if there is an intersection use a dot product
        // to better visualize the part of the triangle
        float dot = -ray.direction().dot(intersection.triangle()->normal());
        if (dot < 0.0f) dot = 0.0f;
        pixel_buffer(j, i) = Vector3f(dot, dot, dot);
      } else {
        // if there is no intersection use color black
        pixel_buffer(j, i) = Vector3f(0, 0, 0);
      }
    }
  }
}