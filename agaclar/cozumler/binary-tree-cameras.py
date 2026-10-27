import itertools

class Solution:

    def minCameraHelper(self, root: Optional[TreeNode]) -> (int, int):
        if not root.left and (not root.right):
            return (1, float('inf'), 0)
        if root.left:
            left_cam, left_uncam, left_uncov = self.minCameraHelper(root.left)
        else:
            left_cam, left_uncam, left_uncov = (float('inf'), 0, 0)
        if root.right:
            right_cam, right_uncam, right_uncov = self.minCameraHelper(root.right)
        else:
            right_cam, right_uncam, right_uncov = (float('inf'), 0, 0)
        cam_poss = itertools.product([left_cam, left_uncam, left_uncov], [right_cam, right_uncam, right_uncov])
        uncam_poss = [(left_cam, right_cam), (left_uncam, right_cam), (left_cam, right_uncam)]
        uncov_poss = [(left_uncam, right_uncam)]
        cam = min([x + y for x, y in cam_poss]) + 1
        uncam = min([x + y for x, y in uncam_poss])
        uncov = min([x + y for x, y in uncov_poss])
        return (cam, uncam, uncov)

    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        cam, uncam, _ = self.minCameraHelper(root)
        return min(cam, uncam)
