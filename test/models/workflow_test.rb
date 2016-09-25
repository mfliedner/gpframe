# == Schema Information
#
# Table name: workflows
#
#  id          :integer          not null, primary key
#  path        :string
#  name        :string
#  description :text
#  project_id  :integer
#  creator_id  :integer
#  history     :text
#  created_at  :datetime         not null
#  updated_at  :datetime         not null
#

require 'test_helper'

class WorkflowTest < ActiveSupport::TestCase
  # test "the truth" do
  #   assert true
  # end
end
