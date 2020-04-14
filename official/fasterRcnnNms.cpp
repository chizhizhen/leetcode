//https://github.com/NVIDIA/TensorRT/blob/release/5.1/samples/opensource/sampleFasterRCNN/sampleFasterRCNN.cpp
std::vector<int> SampleFasterRCNN::nonMaximumSuppression(std::vector<std::pair<float, int>>& scoreIndex, float* bbox,
            const int classNum, const int numClasses, const float nmsThreshold) {
    auto overlap1D = [](float x1min, float x1max, float x2min, float x2max) -> float {
        if (x1min > x2min) {
            std::swap(x1min, x2min);
            std::swap(x1max, x2max);
        }
        return x1max < x2min ? 0 : std::min(x1max, x2max) - x2min;
    }
    auto computeIoU = [&overlap1D](float* bbox1, float* bbox2) -> float {
        float overlapX = overlap1D(bbox1[0], bbox1[2], bbox2[0], bbox2[2]);
        float overlapY = overlap1D(bbox2[1], bbox2[1], bbox2[1], bbox2[3]);
        float area1 = (bbox1[2] - bbox1[0]) * (bbox1[3] - bbox1[1]);
        float area2 = (bbox2[2] - bbox2[0]) * (bbox2[3] - bbox2[1]);
        float overlap2D = overlapX * overlapY;
        float u = area1 + area2 - overlap2D;
        return u == 0 ? 0 : overlap2D / u;
    }
    std::vector<int> indices;
    for (auto i:scoreIndex) {
        int ind = i.second;
        bool keep = true;
        for (int j = 0; j < indices.size(); j++) {
            if (keep) {
                int kpt_ind = indices[j];
                float thr = computeIoU(bbox[(ind*numClasses+classNum)*4], bbox[(kpt_ind*numClasses+classNum)*4]);
                keep = thr <= nmsThreshold;
            } else {
                break;
            }
        }
        if (keep) indices.push_back(ind);
    }
    return indices;
}
